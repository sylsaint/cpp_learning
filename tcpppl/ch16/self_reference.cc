#include<iostream>

// use self reference to get chained funcs

class Date {
    private:
        int d, m, y;
        bool leap_year(int y);
    public:
        explicit Date(int dd = 0, int mm = 0, int yy = 0);
        Date& add_year(int n);
        Date& add_month(int n);
        Date& add_day(int n);

        int get_year() { return y; };
        int get_month() { return m; };
        int get_day() { return d; };
};

Date::Date(int dd, int mm, int yy) {
    d = dd;
    m = mm;
    y = yy;
}

Date& Date::add_year(int n) {
    if (d == 29 && m == 2 && !leap_year(y+n)) {
        d = 1;
        m = 3;
    }
    y += n;
    return *this;
}

Date& Date::add_month(int n) {
    int months[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(m+n <= 12) {
        m += n;
    } else {
        int added_year = (m+n)/12;
        y += added_year; 
        m = (m+n)%12;
    }
    return *this;
}

Date& Date::add_day(int n) {
    int months[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if(leap_year(y) && m == 2) {
        if(d+n <= months[m]+1) {
            d += n;
        } else {
            std::cout << "not supported" << std::endl;
        }
    } else {
        if(d+n <= months[m]) {
            d += n;
        } else {
            std::cout << "not supported" << std::endl;
        }
    }
    return *this;
}

bool Date::leap_year(int y) {
    if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
        return true;
    }
    return false;
}

int main() {
    Date d {1, 5, 2017};
    d.add_year(1).add_month(11).add_day(1);
    std::cout << d.get_year() << std::endl;
    std::cout << d.get_month() << std::endl;
    std::cout << d.get_day() << std::endl;
    return 0;
}
