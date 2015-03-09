#include <iostream>
#include <string>

using std::cin;

class Sales_data {

friend std::istream &read(std::istream &is, Sales_data &item);

public:
    // nondelegating constructor initializes members from corresponding arguments
    Sales_data(std::string s, unsigned cnt, double price):
            bookNo(s), units_sold(cnt), revenue(cnt*price)
            { std::cout << "Sales_data(std::string, unsigned, double)" << std::endl; }

    // remaining constructors all delegate to another constructor.
    Sales_data(): Sales_data("", 0, 0)
      { std::cout << "Sales_data()" << std::endl; }

    Sales_data(std::string s): Sales_data(s, 0, 0)
      { std::cout << "Sales_data(std::string)" << std::endl; }

    Sales_data(std::istream &is): Sales_data()
      {
        std::cout << "Sales_data(std::istream&)" << std::endl;
        read(is, *this);
      }

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// input transactions contain ISBN, number of copies sold, and sales price
std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

int main() {

    Sales_data first_item(cin);

    Sales_data next;

    Sales_data last("9-999-99999-9");
}
