#include<iostream>

int main()
{
    int i = 10;
    void *p = &i;
    if(p == &i)
        std::cout << "same address" << std::endl;
    // std::cout << *p << std::endl;
    const int j = 42;
    // void *pc = &j; error
    return 0;
}
