#include<iostream>

void f(int val, const int& ref)
{
    std::cout << "ref addr == " << &ref << std::endl;
    val += ref;
    std::cout << "in func:f val == " << val << std::endl;
}

void g()
{
    int i = 1;
    int j = 1;
    std::cout << "j addr == " << &j << std::endl;
    std::cout << "befor func:f i == " << i << std::endl;
    f(i, j);
    std::cout << "after func:f i == " << i << std::endl;
    std::cout << "after func:f j == " << j << std::endl;
}

int main()
{
    g();
}
