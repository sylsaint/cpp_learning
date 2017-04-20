#include<iostream>

void g(float&& flt)
{
    std::cout << "flt == " << flt << std::endl;
}

int main()
{
    double d = 25.3;
    float f = 15.4;
    f = static_cast<float>(d);
    // g(f);
    g(static_cast<float>(d));
}
