/*
 * References:
 *
 *   [isocpp] How can it help me design better classes if I distinguish logical state from physical state?
 *     https://isocpp.org/wiki/faq/const-correctness#logical-vs-physical-state
 *
 *   [meyers20050512] Effective C++ (Third Edition) - Item 3: Use const whenever possible
 *     https://www.amazon.com/gp/product/0321334876
 *
 *   [subramaniyan20171028] Logic Constness and Bitwise Constness in c++
 *     https://youtu.be/bKIqdkjWFfU
 *
 *  [chatterjee20170307] Check for const correctness with the C++ Core Guidelines Checker
 *     https://blogs.msdn.microsoft.com/vcblog/2017/03/07/check-for-const-correctness-with-the-c-core-guidelines-checker/
 *
 *   [sutter20130524] GotW #6a Solution: Const-Correctness, Part 1
 *     https://herbsutter.com/2013/05/24/gotw-6a-const-correctness-part-1-3/
 *
 *   [qian20130213] Advanced C++: Logic Constness and Bitwise Constness
 *     https://youtu.be/8A5AwX6XExw
 *
 *   [stackoverflow20100930] difference between logical and physical const-ness
 *     https://stackoverflow.com/questions/3830367/difference-between-logical-and-physical-const-ness
 *
 *   [gilemonster20060507] Discussion Topic #1: Logical vs. Bitwise constness 
 *     http://writebettercode.org/2006/05/discussion-topic-1-logical-vs-bitwise.html
 *
 *   [wilson20050201] Flexible C++ #10: Beware Logical Constness
 *     http://www.drdobbs.com/flexible-c-10-beware-logical-constness/184403892
 *
 *   [eckelXXXXXXXX] Thinking in C++ - mutable: bitwise vs. logical const
 *     https://www.linuxtopia.org/online_books/programming_books/thinking_in_c++/Chapter08_025.html
