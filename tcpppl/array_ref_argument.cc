#include<iostream>

void f(int(&r)[4])
{
    std::cout << r[3]++ << std::endl;
}

void g()
{
    int a1[] {1,2,3,4};
    f(a1);
    std::cout << a1[3] << std::endl;
}

int main()
{
    g();
}
