#include<iostream>
#include "source_code/1/Sales_item.h"

int main()
{
    Sales_item total, item;
    std::cin >> total;
    while (std::cin >> item)
        total += item;
    std::cout << total << std::endl;
    return 0;
}
