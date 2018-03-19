#include<iostream>
#include<string>
#include "sales_data.h"

using namespace std;

int main()
{
    Sales_data sd;
    read(cin, sd);
    print(cout, sd) << endl;
    return 0;
}
