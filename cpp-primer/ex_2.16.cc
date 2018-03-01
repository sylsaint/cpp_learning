#include<iostream>

int main()
{
    int i = 0, &r1 = i;
    double d = 0, &r2 = d;

    r2 = 3.14159;       // valid, assignment
    r2 = r1;            // valid, assignment i to d, implicit type conversion 
    i = r2;             // valid, implicit type conversion
    r1 = d;             // valid, assignment d to i, implicit type conversion 
    return 0;
}
