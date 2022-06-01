/**
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
 * CRTP is some kind of static (compile-time) polymorphism technique.
 * It is sometimes also referred to as the 'Barton-Nackman trick', but that
 * is incorrect, see [vandevoorde20021112], section 16.5 on page 299.  CRTP
 * can be used for the following things:
 *
 *   -> add functionality to a class by inheriting from the base class.
 *
 *   -> create static interfaces (the difference with traditional polymorphism
 *      is that there is no virtual involved and all calls are resolved during
 *      compilation). Note however that this technique is not the best one for
 *      static interfaces, and nowhere as good as what concepts are expected
 *      to bring (see [boccara20170516]).
 *
 * References:
 *
 *   [wikipedia] Curiously recurring template pattern
 *     https://en.wikipedia.org/wiki/Curiously_recurring_template_pattern
 *
 *   [grimm20220228] More about Dynamic and Static Polymorphism
 *     http://www.modernescpp.com/index.php/more-about-dynamic-and-static-polymorhism
 *
 *   [boccara20180622] Variadic CRTP: An Opt-in for Class Features, at Compile Time
 *     https://www.fluentcpp.com/2018/06/22/variadic-crtp-opt-in-for-class-features-at-compile-time/
 *
 *   [EverythingCpp20170613] CRTP: Curiously Recurring Template Pattern
 *     https://youtu.be/2AwZRWt2suc
 *
 *   [boccara20170519] An Implementation Helper For The Curiously Recurring Template Pattern
 *     https://www.fluentcpp.com/2017/05/19/crtp-helper/
 *
 *   [boccara20170516] What the CRTP can bring to your code
 *     http://www.fluentcpp.com/2017/05/16/what-the-crtp-brings-to-code/
 *
 *   [boccara20170512] The Curiously Recurring Template Pattern (CRTP)
 *     http://www.fluentcpp.com/2017/05/12/curiously-recursive-template-pattern/
 *
 *   [boccara20170509] An implementation helper for the CRTP
 *     http://www.fluentcpp.com/2017/05/19/crtp-helper/
 *
 *   [dewhurst20170328] Variadic CRTP
 *     http://stevedewhurst.com/once_weakly/once-weakly20170328/once-weakly20170328.pdf
 *
 *   [grimm20161216] C++ ist doch lazy!
 *     http://www.grimm-jaud.de/index.php/blog/c-ist-doch-lazy
 *
 *   [nanjappa20150709] A simple example to understand CRTP
 *     http://codeyarns.com/2015/07/09/how-to-understand-crtp/
 *
 *   [bendersky20131205] The cost of dynamic (virtual calls) vs. static (CRTP) dispatch in C++
 *     https://eli.thegreenplace.net/2013/12/05/the-cost-of-dynamic-virtual-calls-vs-static-crtp-dispatch-in-c
 *
 *   [bendersky20110517] The Curiously Recurring Template Pattern in C++
 *     https://eli.thegreenplace.net/2011/05/17/the-curiously-recurring-template-pattern-in-c/
 *
 *   [nasonov200512XX] Better Encapsulation for the Curiously Recurring Template Pattern
 *     https://accu.org/index.php/journals/296
 *
 *   [vandevoorde20021112] C++ Templates: The Complete Guide (section 16.3).
 *     http://www.informit.com/articles/article.aspx?p=31473&seqNum=3
 *
 *   [bartonnackman1997XXXX] Scientific and Engineering C++ (Section 12.6: Restricted Template Expansion)
 *     
 *   [coplien199502XX] Curiously Recurring Template Patterns
 *     http://sites.google.com/a/gertrudandcope.com/info/Publications/InheritedTemplate.pdf
 */

#include <iostream>

template <typename Derived>
struct Base{

  void interface() {
    static_cast<Derived*>(this)->implementation();  // this is the key point of the CRTP idiom: dispatch to the implementation of the derived class
  }

  void implementation() {
    std::cout << "Implementation Base" << std::endl;  // default implementation for the static polymorphism for the class Derived3
  }

};

struct Derived1: Base<Derived1>{
  void implementation(){
    std::cout << "Implementation Derived1" << std::endl;
  }
};

struct Derived2: Base<Derived2>{
  void implementation(){
    std::cout << "Implementation Derived2" << std::endl;
  }
};

struct Derived3: Base<Derived3>{};

template <typename T>
void execute(T& base) {
    base.interface();  // in this function template, we use static polymorphism
}


int main()
{
  Derived1 d1;
  execute(d1);  // Implementation Derived1

  Derived2 d2;
  execute(d2);  // Implementation Derived2

  Derived3 d3;
  execute(d3);  // Implementation Base
}
