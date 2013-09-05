#include <iostream>
#include <string>

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

int main()
{
    Sales_data total;

    if (cin >> total.bookNo >> total.units_sold >> total.revenue) {

        total.revenue = total.units_sold*total.revenue;

        Sales_data trans;

        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {

            if ( total.isbn() == trans.isbn() ) {
                total.combine(trans);
            } else {
                cout << total.isbn() << " " << total.units_sold << " " << total.revenue << " " << endl;
                total = trans;
                total.revenue = total.units_sold*total.revenue;
            }
        }
        cout << total.isbn() << " " << total.units_sold << " " << total.revenue << " " << endl;
    } else {
        cerr << "No data?!" << endl;
    }
}
