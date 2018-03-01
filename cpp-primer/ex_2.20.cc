#include<iostream>

int main()
{
    int i = 0;
    double* p = &i; // illegal, type not matched
    int *p0 = i;     // illegal, i is not address
    int *p1 = &i;    // correct
    return 0;
}
