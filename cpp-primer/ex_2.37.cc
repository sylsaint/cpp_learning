#include<iostream>

int main()
{
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype(a = b) d = a;
    ++c;
    ++d;
    std::cout << "c: " << c << std::endl; // output 4
    std::cout << "a: " << a << std::endl; // output 4
    return 0;
}
