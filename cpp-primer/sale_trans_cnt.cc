#include<iostream>
#include "source_code/1/Sales_item.h"

int main()
{
    Sales_item total, item;
    if (std::cin >> total)
    {
        int cnt = 1;
        while (std::cin >> item)
        {
            if (total.isbn() == item.isbn())
                cnt += 1;
            else
            {
                std::cout << total << " occurs " << cnt << " times " << std::endl;
                total = item;
                cnt = 1;
            }
        }
        std::cout << total << " occurs " << cnt << " times " << std::endl;
    }
    return 0;
}
