#include<iostream>

int main()
{
    int i = 42;
    int *p = &i;
    *p = *p * *p; // output 42x42
    std::cout << *p << std::endl;
    return 0;
}
