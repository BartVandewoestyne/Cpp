#include <iostream>
#include <string>

using std::cin;

class Sales_data {

friend std::istream &read(std::istream &is, Sales_data &item);

public:

    // defines the default constructor as well as one that takes a string argument
    Sales_data(std::string s = ""): bookNo(s)
        { std::cout << "Sales_data(std::string)" << std::endl; }

    // remaining constructors unchanged
    Sales_data(std::string s, unsigned cnt, double rev):
      bookNo(s), units_sold(cnt), revenue(rev*cnt)
        { std::cout << "Sales_data(std::string, unsigned, double)" << std::endl; }

    Sales_data(std::istream &is)
        {
          read(is, *this);
          std::cout << "Sales_data(std::istream)" << std::endl;
        }

    // TODO: don't use this print function, but do it the proper way.
    void print() {
      std::cout << "bookNo: = " << bookNo << std::endl;
      std::cout << "units_sold: = " << units_sold << std::endl;
      std::cout << "revenue = " << revenue << std::endl;
      std::cout << std::endl;
    }

    // remaining members as before

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

    Sales_data first_item(cin);        // Sales_data(std::istream)
    first_item.print();
      // bookNo: = a
      // units_sold: = 4
      // revenue = 20

    Sales_data next;                   // Sales_data(std::string)
    next.print();
      // bookNo: = 
      // units_sold: = 0
      // revenue = 0

    Sales_data last("9-999-99999-9");  // Sales_data(std::string)
    last.print();
      // bookNo: = 9-999-99999-9
      // units_sold: = 0
      // revenue = 0
}
