#include<iostream>

struct Base {
    void f(int n) { 
        std::cout << n << std::endl;
    };
};

struct Derived : Base {
    void f(double n) {
        std::cout << n << std::endl;
    };
};

void g(Derived& d)
{
    d.f(1);
}

int main() {
    auto d = Derived();
    g(d);
    return 0;
}
