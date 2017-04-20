#include<iostream>

int main()
{
    int a[] {1, 2, 3, 4, 5};
    auto glambda = [&a](){ std::cout << "lambda function a[2]: " << a[2] << std::endl; return true;};
    bool b = glambda();
    return 0;
}
