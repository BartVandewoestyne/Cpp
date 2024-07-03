/*
 * References:
 *
 *   [fertig2024XXXX] C++20's Coroutines for Beginners - Andreas Fertig - C++Online 2024
 *     https://www.youtube.com/watch?v=4xdef0fRsQ0
 *
 *   [fertig20220912] C++20øs Coroutines for Beginners - Andreas Fertig - CppCon 2022
 *     https://youtu.be/8sEe-4tig_A
 *
 *   [toth20210926] C++20 Coroutines ó Complete* Guide
 *     https://itnext.io/c-20-coroutines-complete-guide-7c3fc08db89d
 *
 *   [chovatiyaXXXXXX] C++20 Coroutine: Under The Hood
 *     http://www.vishalchovatiya.com/cpp20-coroutine-under-the-hood/
 *
 *   [bond20210916] C++20 Coroutines
 *     https://blog.feabhas.com/2021/09/c20-coroutines/
 *
 *   [gulgulia20210531-20210906] Painless C++ Coroutines
 *     https://ggulgulia.medium.com/painless-c-coroutines-part-1-ba90dd101adb (Part 1)
 *     https://ggulgulia.medium.com/painless-coroutines-part2-29b36008b507 (Part 2)
 *     https://ggulgulia.medium.com/painless-c-coroutine-part-3-536e4bce4f4f (Part 3)
 *
 *   [chen20210405] C++ coroutines: Making the promise itself be the shared state, the outline
 *     https://devblogs.microsoft.com/oldnewthing/20210405-00/?p=105054
 *
 *   [chen20210402] C++ coroutines: Making the promise itself be the shared state, the inspiration
 *     https://devblogs.microsoft.com/oldnewthing/20210402-00/?p=105047
 *
 *   [chen20210401] C++ coroutines: What happens if an exception occurs in my return_value?
 *     https://devblogs.microsoft.com/oldnewthing/20210401-00/?p=105043
 *
 *   [chen20210331] C++ coroutines: The initial and final suspend, and improving our return_value method
 *     https://devblogs.microsoft.com/oldnewthing/20210331-00/?p=105028
 *
 *   [chen20210330] C++ coroutines: Basic implementation of a promise type
 *     https://devblogs.microsoft.com/oldnewthing/20210330-00/?p=105019
 *     
 *   [grimm20210301] Implementing Simple Futures with Coroutines
 *     http://www.modernescpp.com/index.php/implementing-futures-with-coroutines
 *
 *   [grimm20210301] C++20: Einfache Futures mit Coroutinen implementieren
 *     https://www.heise.de/developer/artikel/C-20-Einfache-Futures-mit-Coroutinen-implementieren-5066861.html
 *
 *   [mazi√®res202102XX] My tutorial and take on C++20 coroutines
 *     https://www.scs.stanford.edu/~dm/blog/c++-coroutines.html
 *
 *   [grimm20200416] C++20: Coroutines with cppcoro
 *     http://www.modernescpp.com/index.php/c-20-coroutines-with-cppcoro
 *
 *   [chen20191216] C++ coroutines: Short-circuiting suspension, part 2
 *     https://devblogs.microsoft.com/oldnewthing/20191216-00/?p=103217
 *
 *   [chen20191213] C++ coroutines: Short-circuiting suspension, part 1
 *     https://devblogs.microsoft.com/oldnewthing/20191213-00/?p=103210
 *
 *   [chen20191210] C++ coroutines: Constructible awaitable or function returning awaitable?
 *     https://devblogs.microsoft.com/oldnewthing/20191210-00/?p=103197
 *
 *   [chen20191209] C++ coroutines: Getting started with awaitable objects
 *     https://devblogs.microsoft.com/oldnewthing/20191209-00/?p=103195
 *
 *   [barbati20190615] Coroutines in practice (itCppCon19)
 *     https://youtu.be/sUajXn2YCgg
 *
 *   [nikolov20190505] Coroutines & Concurrency in C++
 *     https://stoyannk.wordpress.com/2019/05/05/coroutines-concurrency-in-c/
 *
 *   [dongha20190406] Exploring the C++ Coroutine
 *     https://github.com/luncliff/coroutine/wiki/ppt/%5BEng%5DExploringTheCppCoroutine.pdf
 *
 *   [baker20180905] C++ Coroutines: Understanding the promise type
 *     https://lewissbaker.github.io/2018/09/05/understanding-the-promise-type
 *
 *   [allsopp20180108] Coroutines: what can't they do?
 *     https://channel9.msdn.com/Events/GoingNative/CppCon-2017/014
 *
 *   [nishanov20170928] Naked coroutines live (with networking)
 *     https://youtu.be/UL3TtTgt3oU
 *
 *   [baker20171117] C++ Coroutines: Understanding operator co_await
 *     https://lewissbaker.github.io/2017/11/17/understanding-operator-co-await
 *
 *   [baker20170925] Coroutine Theory
 *     https://lewissbaker.github.io/2017/09/25/coroutine-theory
 *
 *   [nishanov20170719] Coroutines with Gor Nishanov
 *     http://cppcast.com/2017/07/gor-nishanov/
 *
 *   [saelensminde20170623] How C++ coroutines work
 *     https://kirit.com/How%20C%2B%2B%20coroutines%20work
 *
 *   [battalio20170519] Using C++ Coroutines with Boost C++ Libraries
 *     https://blogs.msdn.microsoft.com/vcblog/2017/05/19/using-c-coroutines-with-boost-c-libraries/
 *
 *   [williams20170429] Concurrency, Parallelism and Coroutines - Anthony Williams [ACCU 2017]
 *     https://youtu.be/UhrIKqDADX8
 *
 *   [allsopp20170422] Coroutines and Reference Parameters
 *     https://toby-allsopp.github.io/2017/04/22/coroutines-reference-params.html
 *
 *   [grimm20170228] Coroutines
 *     http://www.modernescpp.com/index.php/coroutines
 *
 *   [nishanov20160920] C++ Coroutines: Under the covers - Gor Nishanov [CppCon 2016]
 *     https://channel9.msdn.com/Events/CPP/CppCon-2016/CppCon-2016-Gor-Nishanov-C-Coroutines-Under-the-covers
 *
 *   [mcnellis20160920] Introduction to C++ Coroutines
 *     https://channel9.msdn.com/Events/CPP/CppCon-2016/CppCon-2016-James-McNellis-Introduction-to-C-Coroutines
 */
