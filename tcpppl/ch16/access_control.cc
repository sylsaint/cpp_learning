#include<iostream>

class Date {
    int d, m, y;
    public:
    void init(int dd, int mm, int yy);

    void add_year(int n);
    void add_month(int n);
    void add_day(int n);

    int year() const;
    int month() const;
    int day() const;
};

void Date::add_year(int n)
{
    y += n;
}

void Date::init(int dd, int mm, int yy)
{
    y = yy;
    m = mm;
    d = dd;
}

int Date::year() const
{
    return y;
}

int main() {
    Date dx;
    dx.init(25, 3, 2011);
    std::cout << dx.year() << std::endl;
    return 0;
}
