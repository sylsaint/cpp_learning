#include<iostream>

// global variables is unmanageable, if used unproperly, it will cause confusions
// static members are bound to class but not object, which can be used across objects
// of class

class Date {
    private:
        int d, m, y;
        static Date default_date;
    public:
        Date(int dd=0, int mm=0, int yy=0);
        static void set_default();
};

// static member must be defined somewhere, but `static` is not repeated.
//
Date Date::default_date {16, 12, 1770};

void Date::set_default() {
    default_date = {25, 5, 2017};
}

// in multithread programming, static data members need some some kind of
// locking and access discipline to avoid data race.


