/*
 * This code is thread-safe according to 
 * References:
 *   [1] http://www.devartplus.com/3-simple-ways-to-create-singleton-in-c/
 *   [2] Concurrency with Modern C++ (singletonSingleThreaded.cpp)
 *   [3] https://arkaitzj.wordpress.com/tag/meyers-singleton/
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
