#include<iostream>

// an unqualified member acts as if it's prefixed by this->
// if we want to access a member in general, not a particular object's member.
// use the :: symbol.

struct X {
    int m;
    int f();
    static int sm;
};

int X::f() {
    return m;
}

int X::sm { 10 };

int main() {
    X x { 10 };
    int(X::*) pmf() {&X::f};
    std::cout << *pmf << std::endl;
    return 0;
}
