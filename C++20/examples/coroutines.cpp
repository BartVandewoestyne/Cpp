/*
 * References:
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
