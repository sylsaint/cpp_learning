#include<iostream>

int main()
{
    int i = 10;
    int *p = &i;
    int j = 20;
    p = &j;
    std::cout << "change pointer value: " << *p << std::endl;
    *p = 31;
    std::cout << "change value to which pointer points: " << *p << std::endl;
    return 0;
}
