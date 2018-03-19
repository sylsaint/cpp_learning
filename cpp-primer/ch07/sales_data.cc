#include<iostream>
#include<string>
#include "sales_data.h"

using namespace std;

Sales_data& Sales_data::combine(const Sales_data& trans)
{
    units_sold += trans.units_sold;
    revenue += trans.revenue;
    return *this;
}

// nonmember functions of Sales_data
Sales_data add(const Sales_data& s1, const Sales_data& s2)
{
    Sales_data sum = s1;
    sum.combine(s2);
    return sum;
}
ostream &print(ostream &os, const Sales_data &sd)
{
    os << "isbn: " << sd.isbn()
        << " units_sold: " << sd.units_sold
        << " revenue: " << sd.revenue;
    return os;
}
istream &read(istream &is, Sales_data &sd)
{
    is >> sd.bookNo >> sd.units_sold >> sd.revenue;
    return is;
}
