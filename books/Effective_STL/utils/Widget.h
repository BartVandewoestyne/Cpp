#ifndef WIDGET_H
#define WIDGET_H

#include <ostream>

class Widget {

friend bool operator==(const Widget& lhs, const Widget& rhs);
friend std::ostream& operator<<(std::ostream& os, const Widget& rhs);

public:

    Widget();
    Widget(int id);

    void setId(int id);
    int getId() const;

private:

    int id;

};

#endif /* WIDGET_H */
