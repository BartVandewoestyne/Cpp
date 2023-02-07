/*
 * Key ideas:
 *
 *   - Using std::byte also has disadvantages.  For example, when compiled in
 *     debug mode, without optimizations, has more overhead compared to char
 *     (See [romeo2022XXXX] at 19:52)
 *
 * References:
 *
 *   [romeo2022XXXX] Pragmatic Simplicity - Actionable Guidelines To Tame Cpp Complexity - Vittorio Romeo - CppCon 2022
 *     https://youtu.be/3eH7JRgLnG8
 *
 *   [codingjesus20200707] C++ - std::byte
 *     https://youtu.be/VTsOJIcBpRQ
 *
 *   [mertz20181128] std::string is not a Container for Raw Data
 *     https://arne-mertz.de/2018/11/string-not-for-raw-data/
 *
 *   [gregoire20180603] C++17: std::byte
 *     http://www.nuonsoft.com/blog/2018/06/03/c17-stdbyte/
 *
 *   [grimm20170417] C++17: std::byte und std::filesystem
 *     http://www.grimm-jaud.de/index.php/blog/c-17-std-byte-und-std-filesystem
 */
