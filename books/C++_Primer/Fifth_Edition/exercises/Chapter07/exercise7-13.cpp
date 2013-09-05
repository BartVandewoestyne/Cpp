#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

// TODO: check if these two lines are the cleanest solution to solve the problem
// with the read function begin used in the istream constructor.
class Sales_data;
istream &read(istream &is, Sales_data &item);

struct Sales_data {
    // constructors added
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p) :
               bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(std::istream &is) { read(is, *this); }  // TODO: check if problem with read was nicely solved.

    // other members as before
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue; // TODO: this is from the book, but is this correct???
    return *this;
}


Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

// input transactions contain ISBN, number of copies sold, and sales price
istream &read(istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue << " " /* TODO  << item.avg_price() */ ;
    return os;
}

int main()
{
    Sales_data total(cin);

    if (cin) {

        while (cin) {

            Sales_data trans(cin);

            if ( total.isbn() == trans.isbn() ) {
                total.combine(trans);
            } else {
                print(cout, total) << endl;
                total = trans;
            }
        }
    } else {
        cerr << "No data?!" << endl;
    }
}
