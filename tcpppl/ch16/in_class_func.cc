#include<iostream>

// a member function is defined in class definition is taken to be inline
// there are two kinds of styles
//
// first


class Date {
    private:
        int d, m, y;
    public:
        explicit Date(int dd = 0, int mm = 0, int yy = 0);
        void add_month(int n) { m += n; }
};

Date::Date(int dd, int mm, int yy) {
    d = dd;
    m = mm;
    y = yy;
}

// second

class DateInline {
    private:
        int d, m, y;
    public:
        explicit DateInline(int dd = 0, int mm = 0, int yy = 0);
        void add_month(int n);
};

DateInline::DateInline(int dd, int mm, int yy) {
    d = dd;
    m = mm;
    y = yy;
}

inline void DateInline::add_month(int n) {
    m += n;
}

int main() {
    Date d {25, 5, 2017};
    DateInline di {25, 5, 2017};
    return 0;
}
