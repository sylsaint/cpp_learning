#include<iostream>
#include<string>
#include "sales_data.h"

using namespace std;

Sales_data::Sales_data(istream &is)
{
    is >> bookNo >> units_sold >> revenue;
}

int main()
{
    Sales_data sd{cin};
    print(cout, sd) << endl;
    return 0;
}
