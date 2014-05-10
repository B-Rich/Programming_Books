#include <iostream>
#include <string>

using namespace std;

struct Sales_data {
    //first version of sales data
    string isbn() const { return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avgPrice() const;

    string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0; 
};

inline double Sales_data::avgPrice() const {

    if (units_sold)
        return revenue/units_sold;
    else
        return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

istream& read(istream &is, Sales_data &item) {

    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream& print(ostream& os, const Sales_data &item) {

    os << item.isbn() << " " << item.units_sold << " " 
        << item.revenue << " " << item.avgPrice();
    return os; 
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {

    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

