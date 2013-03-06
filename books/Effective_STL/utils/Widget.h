#ifndef WIDGET_H
#define WIDGET_H

#include <ostream>

class Widget {

friend bool operator==(const Widget& lhs, const Widget& rhs);
friend bool operator<(const Widget& lhs, const Widget& rhs); // (see item 7)
friend std::ostream& operator<<(std::ostream& os, const Widget& rhs);

public:

    Widget();                                      // default constructor
                                                   // (see item 6)
    Widget(int id);

    Widget(const Widget&);                         // copy constructor
                                                   // (see item 3)
    Widget& operator=(const Widget&);              // copy assignment operator
                                                   // (see item 3)

    void setId(int id);
    int getId() const;

private:

    int id;

};

#endif /* WIDGET_H */
