#include<iostream>

template<class T, int N> void f(const T(&r)[N])
{
    std::cout << r[0] << std::endl;
}

void g()
{
    int a1[10] {};
    double a2[100] {};
    f(a1);
    f(a2);
}

int main()
{
    g();
}
