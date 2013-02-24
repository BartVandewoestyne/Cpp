#include "Widget.h"
#include <iostream>

bool operator==(const Widget& lhs, const Widget& rhs)
{
    return lhs.id == rhs.id;
}

std::ostream& operator<<(std::ostream& os, const Widget& rhs)
{
    os << "Widget [id = " << rhs.id << "]";
    return os;
}

Widget::Widget()
  : id(0)
{
    std::cout << "Widget()" << std::endl;
}

Widget::Widget(int id)
  : id(id)
{
    std::cout << "Widget(int)" << std::endl;
}

Widget::Widget(const Widget& orig)
  : id(orig.id)
{
    std::cout << "Widget(const Widget&)" << std::endl;
}

Widget& Widget::operator=(const Widget& rhs)
{
    id = rhs.id;
    return *this;
}

void Widget::setId(int id)
{
    this->id = id;
}

int Widget::getId() const
{
    return id;
}
