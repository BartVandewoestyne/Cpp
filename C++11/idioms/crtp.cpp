/*
 * Key idea of CRTP:
 *
 *   A class Derived derives from a class template Base and Base has Derived as a template argument:
 *
 *     template<typename T>
 *     class Base
 *     {
 *         ...
 *     };
 *
 *     class Derived : public Base<Derived>
 *     {
 *         ...
 *     };
 *   
 * References:
 *
 *   [sjostrom20190409] How to Emulate the Spaceship Operator Before C++20 with CRTP
 *     https://www.fluentcpp.com/2019/04/09/how-to-emulate-the-spaceship-operator-before-c20-with-crtp/
 *
 *   [klimenko20180702] CRTP-based platform-dependent optimizations
 *     https://mklimenko.github.io/english/2018/07/02/platform-dependent-crtp/
 */
