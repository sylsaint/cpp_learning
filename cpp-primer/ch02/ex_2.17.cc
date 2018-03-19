#include<iostream>

int main()
{
    int i, &r = i;
    i = 5; r = 10;
    std::cout << i << " " << r << std::endl; // output 10 10
    return 0;
}
