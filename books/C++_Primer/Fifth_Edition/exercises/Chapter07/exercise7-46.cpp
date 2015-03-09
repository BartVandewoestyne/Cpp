// TODO: check these answers.

// (a) A class must provide at least one constructor.
//
//     -> Not true.  If the class declares no constructors, the compiler
//     generates a default constructor automatically.
//
// (b) A default constructor is a constructor with an empty parameter list.
//
//     -> True.  The default constructor is one that takes no arguments (see
//     Section '7.1.4 Constructors' on page 263).
//
// (c) If there are no meaningful default values for a class, the class should
// not provide a default constructor.
//
//    -> I think this is true.  But this also implies that things like
//
//         vector<MyClass> vec(10);
//
//       will not work if MyClass has no default constructor.
//
//
// (d) If a class does not define a default constructor, the compiler generates
// one that initializes each data member to the default value of its associated
// type.
//
//    -> Not true.  The compiler generates a default constructor automatically
//    only if a class declares no constructors (see Section 7.1.4 Constructors
//    on page 263).
