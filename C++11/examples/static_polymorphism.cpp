/*
 * Key ideas:
 *
 *   Dynamic Polymorphism:
 *     - happens at runtime
 *     - typically requires a pointer indirection at run time
 *       (but let's not overestimate the cost of a virtual dispatch... in most cases,
 *        you can ignore them... or otherwise MEASURE!)
 *
 *   Static Polymorphism:
 *     - happens at compiletime
 *     - has no performance cost at run time
 *
 * References:
 *
 *   [grimm20220228] More about Dynamic and Static Polymorphism
 *     http://www.modernescpp.com/index.php/more-about-dynamic-and-static-polymorhism
 */


// This example uses CRTP to obtain static polymorphism.

#include <chrono>
#include <iostream>

auto start = std::chrono::steady_clock::now();

void writeElapsedTime(){
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = now - start;
  
    std::cerr << diff.count() << " sec. elapsed: ";
}

template <typename ConcreteMessage>                        // (1)
struct MessageSeverity{
  void writeMessage(){                                     // (2)
    static_cast<ConcreteMessage*>(this)->writeMessageImplementation();
  }
  void writeMessageImplementation() const {
    std::cerr << "unexpected" << std::endl;
  }
};

struct MessageInformation: MessageSeverity<MessageInformation>{
  void writeMessageImplementation() const {               // (3)
    std::cerr << "information" << std::endl;
  }
};

struct MessageWarning: MessageSeverity<MessageWarning>{
  void writeMessageImplementation() const {               // (4)
    std::cerr << "warning" << std::endl;
  }
};

struct MessageFatal: MessageSeverity<MessageFatal>{};     // (5)

template <typename T>
void writeMessage(T& messServer){                       
	
    writeElapsedTime();                                   
    messServer.writeMessage();                            // (6)
	
}

int main()
{
    MessageInformation messInfo;
    writeMessage(messInfo);
    
    MessageWarning messWarn;
    writeMessage(messWarn);
	
    MessageFatal messFatal;
    writeMessage(messFatal);
}
