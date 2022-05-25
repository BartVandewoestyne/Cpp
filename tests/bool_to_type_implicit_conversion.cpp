/*
 * There seems to be some difference in behavior between different compilers here for this piece of code...
 *
 *   g++.exe (x86_64-posix-seh, Built by strawberryperl.com project) 8.3.0
 *     => C++98 gives warning
 *     => C++11 and C++14 give error
 *
 *   Microsoft (R) C/C++ Optimizing Compiler Version 19.28.29335 for x86
 *     => C++14 and C++17 do not give an error
 *     => c++latest does give an error
 *
 *   See also https://forum.qt.io/topic/121881/bool-to-qbytearray-implicit-conversion-curiosity/5
 */


struct Foo {
  Foo(const char*) {}
};

int main()
{
    Foo f = false;
}
