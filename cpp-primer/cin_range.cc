#include<iostream>

int main()
{
    int val1 = 0, val2 = 0;
    int step = 0;
    std::cin >> val1 >> val2;
    if (val1 > val2)
        step = -1;
    else
        step = 1;
    // range is of the form [a, b)
    for (int i = val1; i != val2; i += step)
        std::cout << i << std::endl;
    return 0;
}
