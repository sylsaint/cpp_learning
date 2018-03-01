#include<iostream>
#include "type_name.h"

int main()
{
    const int i = 42;
    auto j = i;                // j is int
    std::cout << j << " : " << type_name<decltype(j)>() << std::endl;
    const auto &k = i;         // k is const reference to int
    std::cout << k << " : " << type_name<decltype(k)>() << std::endl;
    auto *p = &i;              // p is pointer to const int
    std::cout << p << " : " << type_name<decltype(p)>() << std::endl;
    const auto j2 = i, &k2 = i;// j2 is const int, k2 is const reference to int
    std::cout << j2 << " : " << type_name<decltype(j2)>() << std::endl;
    std::cout << k2 << " : " << type_name<decltype(k2)>() << std::endl;
    return 0;
}
