#include<iostream>

// Pointers to functions have argument types declared just like the functions themselves. In pointer
// assignments, the complete function type must match exactly

using namespace std;


void f1(string s)
{
    std::cout << s << std::endl;
}

int f2(string s)
{
    std::cout << s << std::endl;
    return 0;
}

void f3(int* p)
{
    std::cout << *p << std::endl;
}

void f()
{
    void (*pf)(string);
    pf = &f1;

    pf("Bolzano");
}

void err()
{
    void (*pf)(string);
    pf = &f2;
    pf("Cauchy");
}

int main()
{
    f();
    return 0;
}
