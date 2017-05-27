#include<iostream>

using namespace std;

// a class is called concrete class if its representation is definition
//
// it can be used for creating objects

namespace Chrono {
    enum class Month { Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
    class Date {
        public:
            class Bad_date{};
            explicit Date(int dd={}, int mm={}, int yy={});  // {} pick a default

            // non-modifying functions
            int year() const;
            int month() const;
            int day() const;

            int string_rep() const;
            int char_rep() const;

            // modifying functions
            Date& add_year(int n);
            Date& add_month(int n);
            Date& add_day(int n);
        private:
            bool is_valid();
            int d, m, y;
    };

    bool is_date(int d, Month m, int y);
    bool is_leapyear(int y);

    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);

    const Date& default_date();

    ostream& operator<<(ostream& os, const Date& d);
    istream& operator>>(istream& is, const Date& d);
}

int main() {
    return 0;
}
