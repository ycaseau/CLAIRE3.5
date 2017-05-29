//+-------------------------------------------------------------+
//| CLAIRE                                                      |
//| ocall.cl                                                    |
//| Copyright (C) 1994 - 2013 Yves Caseau. All Rights Reserved  |
//| cf. copyright info in file object.cl: about()               |
//+-------------------------------------------------------------+

// ------------------------------------------------------------------
// this is the heart of the CLAIRE optimizer : message to function calls
// ------------------------------------------------------------------

// ******************************************************************
// *  Table of contents                                             *
// *    Part 1: Restruction Binding                                 *
// *    Part 2: Generic c_type & c_code                             *
// *    Part 3: specialized c_code                                  *
// *    Part 4: Method optimizing                                   *
// *    Part 5: inline methods                                      *
// ******************************************************************

// ******************************************************************
// *    Part 1: Restruction Binding                                 *
// ******************************************************************

// if mode = true This method finds the unique property that can be used, if any;
// returns () if no restriction exist, and "ambiguous" if it cannot
// answer.
// if mode = false, we return the union of the matching ranges
ambiguous :: keyword()
[restriction!(self:property,l:list,mode:boolean) : any
 ->  for i in (1 .. length(l)) l[i] := ptype(l[i]),
     restriction!(self.Kernel/definition, l, mode)]

// finds a suitable restriction in lr. Returns a restriction for a match,
// list(r) for a possible match (unique), () for no match and ambiguous
// otherwise
[restriction!(lr:list,l:list,mode:boolean) : any
 ->  //[5] call restriction!(~S,~S) // lr, l,
     let open_required := (class!(l[1]).open = 3),  // NEW (v3.00.30) : open(c) = 3 means that c is an
         rep:any := {} in                           // extensibility node
            (for r:restriction in lr
               (if (not(rep) & tmatch?(l, r.domain))
                   (if mode rep := r else rep := r.range, break(true))
                else if (r.domain ^ l)
                   (if not(mode)
                       (//[5] ~S add ~S // r, r.range,
                        rep :U r.range)
                    else if (compiler.safety <= 3 | rep != {} | open_required)
                       (rep := ambiguous, break(true))
                    else rep := r)),
             //[5] exit de restriction -> ~S // rep,
             rep) ]

// special version for Super, which only looks at methods with domains
// bigger than c
[restriction!(c:class,lr:list,l:list) : any
 ->  if (compiler.safety > 3) l[1] := c ^ l[1],
          for r:restriction in lr
             (if (c Core/<=t r.domain[1])         // <yc> 7:98 thanks to <fl> !!!
                 (if tmatch?(l, r.domain) break(r)
                  else if (r.domain ^ l) break(ambiguous))) ]

// uses a second order type {property + function}
[use_range(self:method,%l:list) : type
 -> if (self.inline? & unknown?(typing,self))
        let lv := self.formula.vars,
            %t:type := any,
            %l2 := list{ v.range | v in lv} in
          (for v in lv put(range, v, %l[v.index + 1]),
           %t := c_type(self.formula.body),
           for v in lv put(range, v, %l2[v.index + 1]),
           if (self.range % type) %t :^ self.range,
           if not(%t)
              Cerror("[207] inline ~S: range ~S is incompatible with ~S (inferred)",
                    self, self.range, c_type(self.formula.body)),
           %t)
     else (//[5] will try to use range type with ~S // %l,
           let f := get(typing, self),
               %l2 := list<type>{ptype(u) | u in %l},
               %t1 := self.range,
               %t2 := ((try case f
                       (lambda apply(f, %l2),
                        property   apply(f,%l2),
                        function apply(f, list{ object | n in (1 .. (length(%l) + 1))},
                                          %l2),
                        any %t1)
                      catch any  (//[0] ~S's 2nd-order type failed on ~S // self,%l,
                                  %t1)) as type) in
            (if (sort=(osort(%t1), osort(%t2)) | self.selector = externC) %t2
             else if sort=(any, osort(%t1))
                Union(Core/t1 = any, Core/t2 = %t2)   // forces the sort and preserves the type
             else %t1)) ]



// ******************************************************************
// *    Part 2: Generic c_type & c_code                             *
// ******************************************************************

// this is the optimizer for messages
// It follows the stucture of the evaluator (self_eval)
// optimize is the distributed compiling method equivalent to the
// evaluation "behave" method
[c_type(self:Call) : type
 ->  if (self.selector = function!) function
     else let s := self.selector,
              l := self.args,
              %type := list{ c_type(x) | x in l} in
       (if (s = safe) %type[1]
        else if (s = externC & length(l) = 2 & l[2] % class) (l[2] as class)
        else if (s = new & l[1] % class) (l[1] as class)
        else if (s = check_in & l[2] % type)   // v3.3.16
          (if (length(l) = 2) sort_abstract!(l[2] as type)
           else (l[2] as type))                 // set or list -> could do better
        else if (s = nth & %type[1] <= array)   // a Call array will be generated
                (if (member(%type[1]) <= float) float else member(%type[1]))       // v3.2.42
        else if (s = @ & l[1] % property)
           let p := l[1] as property,
               c := l[2] in
             (if (c % class & (p @ c) % method) set(p @ c) else any)
        else if (s = get & l[1] % relation)
           let r := l[1] as relation in
             case r
              (property let xs := (r @ class!(%type[2])) in
                          case xs
                           (slot (if (xs.range <= bag & compiler.safety < 3)
                                     class!(l[2].range)
                                  else if (xs.default % xs.range) xs.range
                                  else extends(xs.range)),
                            any r.range),
               table (if (r.default % r.range) r.range
                      else extends(r.range)))
        else let r := restriction!(s, %type, true) in
               case r
                (slot (if (s = instances & l[1] % class)
                          Param(arg = list, params = list(of), args = list(set(l[1])))
                      else r.range),
                 method  use_range(r, %type),
                 any (if not(s.restrictions) selector_psort(self)
                      else if (s.open = 3 | r != ambiguous) sort_abstract!(s.range)
                      else sort_abstract!(restriction!(s, %type, false) as type)))) ]

// this is the optimizer for messages : does not use the sort unless there is a macro
c_code(self:Call) : any -> c_code_call(self,void)

[c_code_call(self:Call,sx:class) : any
 -> //[5] c_code_call(~S)  // self,
    let  s := self.selector, l := self.args  in
      (if (l[1] % global_variable & l[1].range = {} & designated?(l[1].value)) l[1] := l[1].value,  // v3.0.05 CHECK !!
       let m := inline_optimize?(self),          // use of a pattern optimization
           b:boolean := (l[1] % property),
           d := daccess(self, compiler.safety > 5) in
       (if (b & s % {write, put} & length(l) = 3) c_code_write(self)
        else if (b & s = put_store & length(l) = 4 & l[4] = true) c_code_write(self)
        else if (b & s = unknown?) c_code_hold(l[1] as property, l[2], unknown, true)
        else if (b & s = known?) c_code_hold(l[1] as property, l[2], unknown, false)
        else if (b & s = erase & l[2] % Variable) c_code(Produce_erase(l[1],l[2]),sx)
        else if (s = safe)
          let y := compiler.safety, b := compiler.overflow?, x := unknown in
             (compiler.safety := 1, compiler.overflow? := true,     // v3.2.50
              x := Call(safe,list(c_code(l[1], sx))),
              compiler.safety := y, compiler.overflow? := b,
              x)
        else if (s % {add, add!} & b) c_code_add(self)
        else if (s % {add, add!} & c_type(l[1]) <= bag) c_code_add_bag(self)    // v3.0.58 : (b | c_type(l[1]) <= bag))
        else if (b & s = delete) c_code_delete(self)
        else if (s % OPT.to_remove            // v2.4.12 c_interface is special
                | (s = c_interface & length(l) = 2 &
                   not(get_module(s) % OPT.legal_modules))) nil
        else if known?(d) d
        else if (m % method) c_inline(m, l, c_srange(m))
        else if (s % {=, !=} & known?(daccess(l[1], true)))
           c_code_hold(l[1].args[1] as property, l[1].args[2], l[2], s = =)
        else if (s % {=, !=} & known?(daccess(l[2], true)))
           c_code_hold(l[2].args[1] as property, l[2].args[2], l[1], s = =)
        else if (s % {put, nth=} & l[1] % table & length(l) = 3)
           c_code_table(self)
        else if (s % {nth_put, nth=} & c_type(l[1]) <= array & length(l) = 3)
           c_code_array(self)
        else if (s = nth | (s = get & l[1] % table) | (s = nth_get & l[1] % array))
           c_code_nth(self)
        else if (s = %) c_code_belong(self)
        else if (s = Id) c_code(eval(l[1]))
        else if (s = function!)
           make_function(string!(extract_symbol(l[1])))
        else if (s = not & l[1] % Select) c_code_not(l[1])
        else if (s = call & l[1] % property)
           c_code(Call(selector = l[1], args = cdr(l)))
        else if (s.open = 3) c_warn(s, l, list{ c_type(x) | x in l})     // v3.2.04
        else if (s = bit_vector & forall(y in self.args |y % integer)) eval(self)
        else if (s = anyObject! |s = object! | (s = add_method & b)) self
        else let %type := list{ c_type(x) | x in l},
                 z := restriction!(s, %type, true) in
               case z
                (slot let %unknown :=  (not(get(default, z) % z.range) &
                                        not(s % OPT.knowns) & compiler.safety < 5) in
                        (if (not(%unknown) | designated?(l[1])) // v3.1.04
                            Call_slot(selector = z,
                                      arg = c_code(l[1], psort(domain!(z))),
                                      test = %unknown)
                         else (//[3] ---- note: ... unsafe access to unknown slot: ~S // self,
                              if compiler.optimize? (notice(), trace(3,"poorly optimized slot access: ~S\n", self)),  // v3.3
                              c_warn(s,l,%type))),
                 method (//[5] found a method //,
                         if (s = nth=) OPT.use_nth= := true,
                         if (void % %type) Cerror("[205] call ~S uses a void argument [~S]",self,%type), // v3.3
                         // <yc> 7/98 : ensure correct namespaces for further reading
                         if (s % {begin,end} & l[1] % module) eval(self),
                         if (last(z.domain) = listargs |
                             (z.domain[1] = void & l[1] != system))
                            open_message(s, l)
                         else c_code_method(z, l, %type, sx)),
                 keyword c_warn(s, l, %type),    // ambiguous ...
                 any c_warn(self, %type)))) ]     // true error


// create the compiled message with necessary protections
[open_message(self:property,l:list) : Call
 ->  selector_register(self),
     let %arg := list{ (if (c_type(x) != void) c_code(x, any)
                        else Cerror("[206] use of void ~S in ~S~S", x, self, l)) |
                       x in l} in
       (if OPT.allocation %arg := list{ c_gc!(x) | x in %arg},
        if (compiler.diet? & exists(x in l | x % class | x % property))
           (warn(), trace(2,"Non diet call ~S(~A) [254]\n",self,l)),
        Call(self, %arg)) ]


// the gc optimization
[c_gc?(self:Call) : boolean
 -> self.selector = function! |
    (if (self.selector = safe) c_gc?(self.args[1])
     else not((stable?(self.selector) & gcsafe?(self.selector.range)))) ]

// ******************************************************************
// *    Part 3: specialized c_code                                  *
// ******************************************************************

// a get message is special since it represent a direct access. The boolean
// tells if we accept a special form of the unknown value
[daccess(self:any,b:boolean) : any
 -> case self
      (Call let l := self.args,
                xs := (if (self.selector = get & l[1] % property)
                          l[1] @ class!(c_type(l[2]))) in
              (if (case xs
                    (slot (b | xs.default % xs.range | srange(xs) = any |
                           srange(xs) = integer)))
                  Call_slot(selector = xs,
                            arg = c_code(l[2], psort(domain!(xs))),
                            test = false)
               else unknown),
       any unknown) ]

// gc_protection: external MUST NOT be protected
// return true <=> the call_slot must be protected
// note that the part about protecting instances(x) is no longer needed (instances(x) does not change)
// v3.2.28: do not protect a float value (it is native and its coercion will force the protection)
c_gc?(self:Call_slot) : boolean
 -> let s:slot := self.selector,
        x := self.arg in
      ((not(gcsafe?(s.range)) & s.range != float) &         // otherwise no reason to worry !
       (s.selector.open >= 1 | not(gcsafe?(domain!(s)))))

c_type(self:Call_slot) : type -> self.selector.range
c_type(self:Call_table) : type -> self.selector.range
c_type(self:Call_array) : type -> (self.test as type)

// write optimization: ss is put, put_store or write
// note that a put(object,x that may be unknown) is hard to compile !
// v2.4.10 -> if x = unknown OK (o.r = NULL) otherwise use store
[c_code_write(self:Call) : any
 -> let p := self.args[1],
        x := self.args[2],
        y := self.args[3], yt := c_type(y),
        ss := self.selector,
        s := restriction!(p, list(c_type(x)), true) in
       (//[5] c_code_write(~S) // self,
        OPT.use_update := true,
        if (p % OPT.to_remove) nil
        else if (case s
                  (slot (yt <= s.range | compiler.safety >= 4)))
           (if (y != unknown & not(yt ^ srange(s)))
               (//[5] ====> ~S ^ ~S = ~S // yt, srange(s), yt ^ srange(s),
                warn(),trace(2,"sort error in ~S: ~S is a ~S [253]\n",self,y,yt)),
            if ((yt <= s.range | yt <= object | srange(s) != object | y = unknown) &   // v2.4.9 protect put
                (ss != write | (Update?(p, x, y) & (p.multivalued? = false | unknown?(if_write,p)))))   // put or put_store  v3.3
               // MAJOR DECISION in v3.3.20 : allow fast update x.l := l2 for multivalued slots (no inverse  & no demons !)
               let %x := c_code(x, psort(domain!(s))),
                   %y := c_strict_code(y, psort(s.range)) in
                 Update(selector = p, value = %y,
                        arg = (if (ss != write) ss else c_code(x, any)),
                        var = Call_slot(selector = s, arg = %x, test = false))
            else if (ss = put)
              c_code(Call(store, list(x,s.index,srange(s),y,p.Kernel/store?)))
            else (if compiler.diet? (warn(), trace(2,"~S is not a diet call [254]",self)),
                  if (compiler.optimize? & p != instances)
                     (notice(), trace(3,"poorly typed update: ~S\n", self)),  // v3.3
                  c_code(Call(mClaire/update, list(p, x, s.index, srange(s), y)))))
        else let %type := list{ c_type(x) | x in self.args},
                 z := restriction!(ss, %type, true) in
               (//[3] ---- note: ~S is poorly typed (~S,~S) // self, c_type(x), yt,
                case z
                (method c_code_method(z, self.args, %type),
                 any c_warn(self, %type)))) ]

// (get(p,x) =/= y) optimization. We try to use the smart form instead of the get
c_code_hold(p:property,x:any,y:any,b:boolean) : any
 -> let s := restriction!(p, list(c_type(x)), true) in
       (if (case s (slot (y = unknown | (c_type(y) <= srange(s) & identifiable?(y)))))
           let cs := Call_slot(selector = s,
                               arg = c_code(x, psort(domain!(s))),
                               test = false),
               cm := Call_method2(arg = (identical? @ any),
                                  args = list(cs, c_code(y, srange(s)))) in
             (if b c_code(cm)
              else c_code(Call(selector = not, args = list(cm))))
        else let l := list(any, any) in
               c_code_method((if b = else !=) @ l,
                             list(c_code(Call(get,list(p, x)),any), c_code(y, any)),
                             l))

// add optimization
c_code_add(self:Call) : any
 ->   let p := (self.args[1] as property),
          x := self.args[2],
          y := self.args[3],
          s := (p @ class!(ptype(c_type(x)))) in   // WARNING: new in v2.0.60 ! use ptype
       (OPT.use_update := true,
        if (case s
             (slot (c_type(y) <= member(s.range) | compiler.safety >= 4)))
           (if Update?(p,self.selector)       // open for using Update if necessary
               let x2 := c_code(x, psort(domain!(s))) in
                 Update(selector = p,
                        arg = add,            // mark => p multivalued !
                        var = Call_slot(selector = s, arg = x2, test = false),
                        value = c_code(y, psort(member(s.range))))
            else if (designated?(x) &                   // new: add is simple
                       ( not(p.mClaire/store?) &        // direct mode does not handle STORE ?
                         (self.selector = add! |unknown?(inverse, p) )))
               let x2 := c_code(x, psort(domain!(s))) in
                  c_code(Call(add,
                              list(Call_slot(selector = s, arg = x2,
                                             test = false), y)))
            else (if compiler.optimize? (notice(), trace(3,"poorly typed update: ~S\n", self)),  // v3.3
                  c_code_method(add! @ property, list(p, x, s.index, y),
                               list(property, c_type(x), integer,
                                    c_type(y)))))
        else c_code_method(add @ property, self.args, list{ c_type(x) | x in self.args}))


// new in v3.0.59
c_code_add_bag(self:Call) : any
 -> let %t1 := c_type(self.args[1]),  // known to be a subset of bag
        %t2 := ptype(c_type(self.args[2])),  // length is more than 2   v3.3: use ptype !
        %p :=  (if ((%t1 % Param & %t2 <= member(%t1)) | compiler.safety >= 4) add!
                else self.selector),
        %ltype := list(%t1,%t2),
        z := restriction!(%p, %ltype, true) in
     (//[5] ~S: ~S -> ~S // self, %ltype, z,
      if (not(%t2 <= member(%t1)) & self.selector = add)
         (warn(),trace(2,"the bag addition ~S is poorly typed (~S) [251] \n",self,member(%t1))),  // v3.3
      case z
       (method c_code_method(z, self.args, %ltype),
        any c_warn(self, %ltype)))

// delete optimization
// <yc> 7/98 new, also needed
c_code_delete(self:Call) : any
 -> (let p := self.args[1],
         x := self.args[2],
         y := self.args[3],
         s := (p @ class!(c_type(x))) in
       (OPT.use_update := true,
        if (unknown?(inverse, p) & designated?(x) &
            (case s (slot (c_type(y) <= member(s.range) | compiler.safety >= 4))))
          let x2 := c_code(x, psort(domain!(s))) in
               c_code(Call(delete,
                          list(Call_slot(selector = s, arg = x2,
                                         test = false), y)))
                ; Update(selector = p, arg = put,
                ;        var = Call_slot(selector = s, arg = x2, test = false),
                ;        value = c_code(Call(delete,
                ;                            list(Call_slot(selector = s, arg = x2,
                ;                                           test = false), y)),
                ;                       bag))
        else c_code_method(delete @ property, self.args, list{ c_type(x) | x in self.args})))

// cute optimization
c_code_not(x:Select) : any
 -> c_code(Call(not, list(For(var = x.var, set_arg = x.set_arg,
                              arg = If(test = x.arg, arg = Return(arg = true),
                                       other = unknown)))))

// old % optimization
[c_code_belong(self:Call) : any
 ->  let x := self.args[1],
         y := self.args[2],
         %type := list(c_type(y), c_type(x)) in     // watch: permutation !
       (if (y % set)
           Or(args =
                list{ c_code(Call(selector = =, args = list(x, z)), any) |
                  z in y})
        else if (%type[1] <= list)  // v3.3.14     | %type[1] <= tuple)           // v3.2.28
           c_code_method(contain? @ list(list, any), list(y, x), %type)
        else if (%type[1] <= set)
           c_code_method(contain? @ list(set, any), list(y, x), %type)
        else if (y = object)
           c_code_method(% @ list(any, class), list(x, y),
                         list(any, class))
        else member_code(y, x)) ]

// nth optimization for arrays (the selector may also be get)
[c_code_nth(self:Call) : any
 ->  let l := self.args,
         x := l[1], p := self.selector,         // p is nth or get !
         t := c_type(x), mt := member(t),
         r := restriction!(p,list{c_type(u) | u in l}, true) in
       (if (x % OPT.to_remove) nil
        else if ((case x (table x.params % integer)) &
                 (c_type(l[2]) <= x.domain |
                    (p = nth & compiler.safety > 2)))
           Call_table(selector = x, arg = c_code(l[2], integer),
                      test = not((x.default % x.range | x.default = 0 | p = get)))
        else if ((case x (table x.params % list)) & length(l) = 3 &
                 (tuple!(list(c_type(l[2]), c_type(l[3]))) <= x.domain |
                  compiler.safety > 2))
           Call_table(selector = x,
                      arg = List(args =
                        list(c_code(l[2], integer), c_code(l[3], integer))),
                      test = not((x.default % x.range | x.default = 0 | p = get)))
        else if (t <= array & (p = nth_get | compiler.safety > 2) &
                 (mt <= float | (mt ^ float = {})))
           Call_array(selector = c_code(x,array), arg = c_code(l[2], integer),
                      test = mt)
        else if (r % method)
           (if (compiler.optimize? & (t <= array | t <= table))
               (notice(), trace(3,"poorly typed call: ~S\n", self)),  // v3.3
            c_code_method(r, self.args, list{ c_type(x) | x in self.args}))
        else c_warn(p, self.args, list{ c_type(x) | x in self.args})) ]

// nth= optimization for tables
[c_code_table(self:Call) : any
 ->  let sp := self.selector,
         p := (self.args[1] as table),
         x := self.args[2],
         y := self.args[3] in
       (if (p % OPT.to_remove) nil
        else if (sp = put |
                 ((c_type(x) <= p.domain | compiler.safety >= 5) &
                  (c_type(y) <= p.range | compiler.safety >= 4)))
           (if (Update?(p, x, y) & (p.params % list | p.params % integer))
               let %x := c_code(x, any),
                   %y := c_code(y, any) in
                 Update(selector = p, value = %y,
                        arg = (if (sp = put) put else %x),
                        var =
                          Call_table(selector = p, arg = %x, test = false))
            else if (sp = put |
                     (unknown?(inverse, p) & unknown?(Kernel/if_write, p)))
               (if compiler.optimize? (notice(), trace(3,"poorly typed update: ~S\n", self)),  // v3.3
                c_code_method(put @ table, self.args, list(table, any, any)))
            else c_code_method(nth_put @ table, self.args,
                               list(table, any, any)))
        else c_code_method(nth= @ table, self.args, list(table, any, any))) ]

// version for arrays
[c_code_array(self:Call) : any
 ->  let sp := self.selector,
         p := self.args[1], tp := c_type(p), mt := member(tp),
         x := self.args[2], y := self.args[3],
         typeok:boolean := (c_type(y) <= member(tp) | compiler.safety >= 4) in
       (if ((sp = nth_put | typeok) & (mt <= float | (mt ^ float = {})))
           let %x := c_code(x, integer),
               %y := c_code(y, (if (mt <= float) float else any)) in  // v2.4.03
                 Update(selector = p, value = %y,
                        arg = put,
                        var = Call_array(selector = c_code(p,array), arg = %x, test = mt))
        else (if compiler.optimize? (notice(), trace(3,"poorly typed update: ~S\n", self)),  // v3.3
              c_code_method( ((if typeok nth_put else sp) @ array),
                            self.args, list(tp, any, any)))) ]

// can we use the special UDATE form ?
[Update?(p:relation,x:any,y:any) : boolean
 -> (p != inverse) &
    ( (known?(Kernel/if_write, p) & not(p.if_write % list)) |
      ( unknown?(inverse, p) &              // MAJOR DECISION IN V3.0.42 : remove not(multi?(p))
        (case p (table p.params % integer, any true)) &
        (if (p.Kernel/store?)
            (designated?(x) & designated?(y) & not(multi?(p)) &
              (identifiable?(y) | c_type(y) <= float))          // v3.2.56: float is ok (STOREF macro)
         else true))) ]

// we do not use an Update form for add
[Update?(p:relation,s:relation) : boolean
   -> known?(if_write,p) & not(p.if_write % list) & s = add ]

// Update returns the value .. <yc:0.01 -> needed in CLAIRE 2.4 !!!>
c_type(self:Update) : type  -> void


// ******************************************************************
// *    Part 3: Method optimizer                                    *
// ******************************************************************

// a basic method is assumed to be compiled if it is in the right module
c_code_method(self:method,l:list,%type:list) : any
 -> c_code_method(self,l,%type,c_srange(self))

c_code_method(self:method,l:list,%type:list,sx:class) : any
 -> (if (self.module! != claire | compiler.safety > 4 |
         known?(functional, self))
        let ld := self.domain,
            n := length(ld) in
          (if (n != length(l))
              l := list{ l[i] | i in (1 .. (n - 1))} add
                   list{ l[i] | i in (n .. length(l))},
           if (self.inline? & c_inline?(self, l))
              c_inline(self, l, sx)
           else let b := OPT.allocation, x:any := nil in
                  (write(allocation, OPT, false),
                   x := Call_method!(self,
                                     list{ c_strict_code(l[i], psort(ld[i])) |
                                           i in (1 .. n)}),
                   if not(OPT.allocation) OPT.allocation := b,
                   x))
     else (if compiler.optimize? (notice(), trace(3,"poorly typed update: ~S\n", self)),  // v3.3
           open_message(self.selector, l)))

// the code to be produced for a method
// SAFE_GC => do not protect the arguments
Call_method!(self:method,%code:list) : any
 -> (if (status!(self)[NEW_ALLOC])
        (OPT.allocation := true,
         if not(self.status[SAFE_GC]) %code := list{ c_gc!(x) | x in %code})
     else if (OPT.allocation &
              length(list{ x in %code | c_gc?(x)}) > 1)
        %code := list{ c_gc!(x) | x in %code},
    // if (self.range = float) OPT.protection := true,    // <yc> 3/10/98 NOT optimal but OK
     if (self.status[BAG_UPDATE]) OPT.use_nth= := true,
     if (self.status[STRING_UPDATE]) OPT.use_string_update := true,  // v3.3.46
     if (self.status[SLOT_UPDATE]) OPT.use_update := true,
     if not(legal?(self.module!, self))
        trace(0,"in call ~S~S\n",self.selector,%code),
     if (length(%code) = 1) Call_method1(arg = self, args = %code)
     else if (length(%code) = 2) Call_method2(arg = self, args = %code)
     else Call_method(arg = self, args = %code))


// a call_method or a call external has an obvious type (we do not need to do
// better ?)
//
c_type(self:Call_method) : type
 -> use_range(self.arg, list{ c_type(x) | x in self.args})

// a call_method is already compiled
c_code(self:Call_method) : any -> self

// gc protection of the result
//   either the status is on, or we received a dangerous argument as a parameter.
// SAFE_GC is set by hand when the result is already protected by the called method
// note that a float call is safe: either it is native, or the value is passed through a
// call to _float_ that already protects the result
c_gc?(self:Call_method) : boolean
 -> (let m := self.arg in
       ((not(gcsafe?(m.range)) & m.range != float) &     // v3.2.28
        ( not(status!(m)[SAFE_RESULT]) |
          not(m.range <= bag & OPT.loop_gc)) &           // v3.2.32 : in a loop SAFE-RESULT may be wrong
        ( not(status!(m)[RETURN_ARG]) |                   // v3.4  RETURN_ARG is an optim : not there => result as expected
          (status!(m)[NEW_ALLOC] | exists( x in self.args | c_gc?(x)))))) // if RETURN_ARG, then gc-protect only if alloc
// was       (status!(m)[NEW_ALLOC] |
//             (m.status[RETURN_ARG] & exists( x in self.args | c_gc?(x))))))

// NOTE (3.4) forcing to true when NEW_ALLOC (& RETURN_ARG) is strange, but RETURN_ARG is currently wrong !
    
// gets the associated function if it exists and create one otherwise
Compile/functional! :: property(open = 3)
[functional!(self:method) : function
 ->  let f := get(functional, self),
         p := self.selector in
       case f (function f,
               any make_function(function_name(p, self.domain, f))) ]

// second-order types for better safety or optimization -------------------------------
[nth_type_check(tl:type,ti:type,tx:type) : any
  =>  if not(tx <= member(tl))
         (warn(), trace(2,"unsafe update on bag: type ~S into ~S [252]\n", tx,tl)),
      tx ]
(write(typing, nth= @ list, nth_type_check))

// ******************************************************************
// *    Part 5: inline methods                                      *
// ******************************************************************

// macro expansion for inline method ?
// we check that it is a good idea
[c_inline?(self:method,l:list) : boolean
 -> let f := self.formula, la := f.vars, x := f.body, n := 1 in
       not((for v in f.vars
              (if (Language/occurrence(x, v) > 1 &
                   not(designated?(l[n])) & not(v.range % Pattern))
                  break(true)
               else n :+ 1))) ]

// checks if a special optization restriction can be used (with patterns)
[inline_optimize?(self:Call) : any
 -> let l := self.args,
        m := restriction!(self.selector, list{ set(x) | x in l}, true) in
       case m
        (method (if (m.inline? & exists(s in m.domain | s % Pattern) 
                     & c_inline?(m, l)) m),
         any false) ]


// eof
