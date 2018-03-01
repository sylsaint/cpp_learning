#include<iostream>

int main()
{
    int i = 10;
    int *p = &i;
    int **pp = &p;
    std::cout << "the value of ival" << std::endl;
    std::cout << i << std::endl;
    std::cout << *p << std::endl;
    std::cout << **pp << std::endl;
    return 0;
}
