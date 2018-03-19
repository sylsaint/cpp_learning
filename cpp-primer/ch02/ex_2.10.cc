#include<iostream>

std::string global_str; // emtpy
int global_int; // 0

int main()
{
    std::string local_str; // empty
    int local_int; // 0

    std::cout << global_str << std::endl;
    std::cout << local_str << std::endl;
    std::cout << global_int << std::endl;
    std::cout << local_int << std::endl;
    return 0;
}
