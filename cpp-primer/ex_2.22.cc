#include<iostream>

int main()
{
    int i = 10;
    int *p = &i;
    int *p1 = nullptr;
    // test normal pointer
    if (*p)
        std::cout << "*P: " << *p << std::endl;
    if (p)
        std::cout << "p: " << p << std::endl;
    // test null pointer
    if (p1 == nullptr)
        std::cout << "*p is nullptr" << std::endl;
    if (*p1)
        std::cout << "*p1: " << *p1 << std::endl;
    if (p1)
        std::cout << "p1: " << p1 << std::endl;
    return 0;
}

