/*
 * References:
 *
 *   [severeijns20220512] Modern C++ In-Depth — Perfect Forwarding
 *     https://medium.com/factset/modern-c-in-depth-perfect-forwarding-570f242261f8
 *
 *   [severeijns20220503] Modern C++ In-Depth — Move Semantics, Part 2
 *     https://medium.com/factset/modern-c-in-depth-move-semantics-part-2-4c53e90d5f2
 *
 *   [severeijns20220302] Modern C++ In-Depth — Move Semantics, Part 1
 *     https://medium.com/factset/modern-c-in-depth-move-semantics-part-1-8a29d33944e4
 *
 *   [josuttis20211026] Back to Basics: Move Semantics - Nicolai Josuttis - CppCon 2021
 *     https://youtu.be/Bt3zcJZIalk
 *
 *   [olsen20200917] Back to Basics: Move Semantics - David Olsen - CppCon 2020
 *     https://youtu.be/ZG59Bqo7qX4
 *
 *   [sutter20200217] Move, simply
 *     https://herbsutter.com/2020/02/17/move-simply/
 *
 *   [iglberger20190916] Back to Basics: Move Semantics - Klaus Iglberger - CppCon 2019
 *     https://youtu.be/St0MNEU5b0o (part 1 of 2)
 *     https://youtu.be/pIzaZbKUw2s (part 2 of 2)
 *
 *   [winward20190117] C++ moves for people who don't know or care what rvalues are
 *     https://medium.com/@winwardo/c-moves-for-people-who-dont-know-or-care-what-rvalues-are-%EF%B8%8F-56ee122dda7
 *
 *   [shahar20180919] Move Semantics
 *     https://shaharmike.com/cpp/move-semantics/
 *
 *   [josuttis20180830] The Nightmare of Move Semantics for Trivial C++ Classes
 *     https://vimeo.com/292914829
 *
 *   [raggi20180717] How to Construct C++ Objects Without Making Copies
 *     https://www.fluentcpp.com/2018/07/17/how-to-construct-c-objects-without-making-copies/
 *
 *   [triangles20180602] C++ rvalue references and move semantics for beginners
 *     https://www.internalpointers.com/post/c-rvalue-references-and-move-semantics-beginners

 *   [Z01_20180212] My Precious Compile Time Bool (long introduction to Move Semantics)
 *     https://medium.com/@gaussnoise/my-precious-compile-time-bool-long-introduction-to-move-semantics-c9ee73c370c7
 *
 *   [maudal20180205] Modern C++ Explained: Move Semantics, Olve Maudal.
 *     http://www.pvv.org/~oma/ModernCPPExplained_MoveSemantics_Feb2018.pdf
 *
 *   [josuttis20170926] The Nightmare of Move Semantics for Trivial Classes
 *     https://youtu.be/PNRju6_yn3o
 *
 *   [hinnant20160916] Everything You Ever Wanted to Know About Move Semantics
 *     https://youtu.be/vLinb2fgkHk
 *
 *   [kalev20120709] Move Semantics in C++11, Part 2: Design and Implementation of Special Move Functions
 *     https://www.informit.com/articles/article.aspx?p=1916419
 *
 *   [kalev20120702] Move Semantics in C++11, Part 1: A New Way of Thinking About Objects
 *     https://www.informit.com/articles/article.aspx?p=1914190
 */
