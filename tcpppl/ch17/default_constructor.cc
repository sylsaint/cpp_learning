#include<iostream>

using namespace std;

struct S1 {
    string s;
};

struct X {
    X(int, int);
};

X::X(int x, int y) {
    cout << "initialized with: " << x  << " and " << y << endl;
}

struct X2 {
    X x;
    X x1;
    S1 s;
};

int main() {
    S1 xs;
    cout << "default constructor: " << xs.s << endl;

    // X2 x2 {{1, 2}};
    X2 x2 {{1, 2}, {3, 4}, "abc"};

    return 0;
}
