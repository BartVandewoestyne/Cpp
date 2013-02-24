#include "SpecialWidget.h"
#include <iostream>

SpecialWidget::SpecialWidget() 
{
    std::cout << "SpecialWidget()" << std::endl;
}

SpecialWidget::SpecialWidget(const SpecialWidget& origin)
  : Widget(origin)
{
    std::cout << "SpecialWidget(const SpecialWidget&)" << std::endl;
}

SpecialWidget& SpecialWidget::operator=(const SpecialWidget& rhs)
{
    std::cout << "SpecialWidget& operator=(const SpecialWidget&)" << std::endl;

    if (this != &rhs) {
        Widget::operator=(rhs);
    }
    return *this;
}
