#include<iostream>

int main()
{
    int ival = 1.01;   // valid
    int &rval1 = 1.01; // invalid, right hand should be an object
    int &rval2 = ival; // valid
    int &rval3;        // invalid, initializer must be provided
    return 0;
}
