#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Sales_data {
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
    Sales_data total;

    if (read(cin, total)) {

        Sales_data trans;

        while (read(cin, trans)) {

            if ( total.isbn() == trans.isbn() ) {
                total.combine(trans);
            } else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total) << endl;
    } else {
        cerr << "No data?!" << endl;
    }
}
