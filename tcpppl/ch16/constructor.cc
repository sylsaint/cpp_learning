#include<iostream>

// default constructor

// Date xmas = Date(2017, 5, 25);
// Date xmas(2017, 5, 25); abbreviated form
// use {}-initializer notation
// Date xmas = Date {2017, 5, 25};
// Date xmas {2017, 5, 25}; abbreviated formo
// prefer {} nonation than ()
//
// constructors obey the same rules for overloading in ordinary functions
//
// default arguments: Date(int yy = 0, int mm = 0, int dd = 0)
//
//
// explicit constructor
// implicit conversions sometimes can be the cause of confusion and errors,
// such as: Date d = {15}; Date d = 15; obscure
//
// using explicit keyword can eliminate the problems
// explicit can not be repeated

class Date {
    private:
        int year, month, day;
    public:
        int get_year();
        int get_month();
        int get_day();
        explicit Date(int = 0, int = 0, int = 0);
};

Date::Date(int yy, int mm, int dd) {
    year = yy;
    month = mm;
    day = dd;
}

struct X {
    explicit X();
    explicit X(int, int);
};

X::X() {
    std::cout << "initialized" << std::endl;
}

X::X(int x, int y) {
    std::cout << "initialized with " << x << " and " << y << std::endl;
}

int f(X x) {
    return 0;
}

// in-class initializer
// Alternatively, we can add initializers to data members

class XD {
    int y {0};
    int m {0};
    int d {0};
    public:
    XD(int, int, int);
    XD(int, int);
};

XD::XD(int dd, int mm, int yy) :d{dd}, m{mm}, y{yy} {
    std::cout << "initialized with " << d << "," << m << "," << y << std::endl;
}

XD::XD(int dd, int mm) :d{dd}, m{mm} {
    std::cout << "initialized with " << d << "," << m << "," << y << std::endl;
}


int main() {

    Date d = Date{2017, 5, 25};
    Date d1 {2017, 5, 25};

    // f({}) error
    f(X{});       // ok
    f(X{1, 2});

    XD xd {25, 5}; // explicit
    return 0;

}


