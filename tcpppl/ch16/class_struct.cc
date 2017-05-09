#include<iostream>

// class definition: class X {};
// struct definition: struct S {};

// use access specifier: private to make struct member private

struct Date {
    private:
        int d, m, y;
    public:
        Date(int dd, int mm, int yy);
        void add_year(int n);
        int year() const;
};

Date::Date(int dd, int mm, int yy): d{dd}, m{mm}, y{yy} {};
void Date::add_year(int n)
{
    y += n;
}
int Date::year() const
{
    return y;
}

int main()
{
    Date dx = Date {25, 3, 2017};
    std::cout << dx.year() << std::endl;
    return 0;
}
