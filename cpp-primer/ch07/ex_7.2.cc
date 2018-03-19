#include<iostream>
#include "sales_data.cc"

Sales_data& Sales_data::combine(const Sales_data& sd)
{
    units_sold += sd.units_sold;
    revenue += sd.revenue;
    return *this;
}

double Sales_data::avg_price() const
{
    return revenue / units_sold;
}

int main()
{
    Sales_data total, trans;
    trans.units_sold = 5;
    trans.revenue = 20.0;
    total.combine(trans);
    cout << "average price: " << total.avg_price() << endl;
    return 0;
}
