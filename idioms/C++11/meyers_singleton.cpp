/*
 * This code is thread-safe according to the references.
 *
 * References:
 *
 *   [grimm2017] Concurrency with Modern C++ (singletonSingleThreaded.cpp)
 *   [generic20110331] http://www.devartplus.com/3-simple-ways-to-create-singleton-in-c/
 *   [jimenez20091107] https://arkaitzj.wordpress.com/tag/meyers-singleton/
 *   [ankur20091102] https://stackoverflow.com/questions/1661529/is-meyers-implementation-of-the-singleton-pattern-thread-safe
 */

class Singleton
{
public:
    static Singleton& getInstance()
    {
        static Singleton instance;
        volatile int dummy{};
        return instance;
    }

private:
  Singleton() = default;
  ~Singleton() = default;
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

};

int main()
{
    Singleton::getInstance();
}
