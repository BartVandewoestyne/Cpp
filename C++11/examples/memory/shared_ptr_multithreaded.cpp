/* 
 * References:
 *
 *   [josuttis20190902-05] C++ Smart Pointers - Usage and Secrets
 *     https://youtu.be/XH4xIyS9B2I?t=1847
 *     
 *   [wang20180911] c++ why std::shared_ptr need atomic_store, atomic_load or why we need atomic shared_ptr
 *     http://www.comrite.com/wp/c-why-need-atomic_store-atomic_load-on-shared_ptr-atomic-shared_ptr/
 *
 *   [park20180903] std::shared_ptr is not thread safe
 *     https://marsettler.com/2018/09/03/shared-ptr-is-not-thread-safe.html
 * 
 *   [pusz20161115] std::shared_ptr<T> (not so) smart hammer for every pointy nail
 *     https://cdn2-ecros.pl/event/codedive/files/presentations/2016/std_shared_ptr.pdf
 *     https://youtu.be/hHQS-Q7aMzg?t=896
 *
 *   [shahar20161113] Exploring std::shared_ptr - Performance & thread safety
 *     https://shaharmike.com/cpp/shared-ptr/#performance-thread-safety
 *
 *   [stackoverflow20150923] Is shared_ptr destruction safe with multiple threads?
 *     https://stackoverflow.com/questions/32750945/is-shared-ptr-destruction-safe-with-multiple-threads
 *
 *  [stackoverflow20140727] Double Delete using Shared Pointers, even though there is still a shared_ptr to the object, its destructor is being called
 *     https://stackoverflow.com/questions/24977582/double-delete-using-shared-pointers-even-though-there-is-still-a-shared-ptr-to
 *
 *   [stackoverflow20130123] std::shared_ptr thread safety
 *     https://stackoverflow.com/questions/14482830/stdshared-ptr-thread-safety
 */
