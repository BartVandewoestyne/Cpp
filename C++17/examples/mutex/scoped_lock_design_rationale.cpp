On
 
  https://stackoverflow.com/questions/43019598/stdlock-guard-or-stdscoped-lock

is the comment

  "The author of scoped_lock Mike Spertus showed me such a case in the hall between meetings a couple of years ago. I'm afraid I don't remember the details well enough to replicate it. And after a quick search I don't find an example online nor in one of Mike's papers. If you desperately need an example I recommend contacting Mike directly. – 
Howard Hinnant
 CommentedDec 21, 2021 at 14:28"

so Ahmad Bamba, one of my colleagues at iDirect who had Mike Spertus as a professor in the past, wrote him and got the following answer:

------------ ANSWER ----------

The use-case for std::scoped_lock allowing 0 or more locks, and doing a no-op if zero locks are used, is to allow generic algorithms to be used in single-threaded or multi-threaded environments without incurring a run-time cost of an unnecessary lock in the single-threaded case. Consider the following:


<<<<< begin code >>>>>
#include <mutex>

template<typename IteratorType, typename... MutexTypes>
void modify_container(IteratorType begin, IteratorType end, MutexTypes... locks)
{
    std::scoped_lock lk(locks...);
    // modify container using iterators
}

// In single-threaded code
// modify_container(list.begin(), list.end());

// In multi-threaded code requiring one mutex
// modify_container(settings.begin(), settings.end(), settings_mutex);

// In multi-threaded code requiring n mutexes
// modify_container(shared_hashtable.begin(), shared_hashtable.end(), read_mutex, write_mutex);


<<<<< end code >>>>>

modify_container called in the single-threaded case without any locks simply modifies the container without locking, allowing the compiler to completely optimize the internal call to std::scoped_lock's constructor away. But if you are calling from threaded code and modifying a shared container, then you can pass one lock in and the algorithm will do the same thing but be thread safe. For cases that require multiple mutexes that need to be locked with a deadlock avoidance algorithm, the modify_container can be reused and will work correctly. This is the reason main reason std::scoped_lock was designed this way
