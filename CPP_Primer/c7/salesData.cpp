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

double Sales_data::avgPrice() const {

    if (units_sole)
        return revenue/units_sold;
    else
        return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this
}
