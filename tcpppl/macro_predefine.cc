#include<iostream>

#define variable(x) std::cout << #x "=";

template<class T>
void printx(T&& t)
{
    variable(t);
    std::cout << t << std::endl;
}

int main()
{
    printx(__cplusplus);
    printx(__DATE__);
    printx(__TIME__);
    printx(__FILE__);
    printx(__LINE__);
    return 0;
}
