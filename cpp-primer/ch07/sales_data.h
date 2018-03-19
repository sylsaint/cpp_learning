#include<iostream>
#include<string>

using namespace std;

struct Sales_data
{
    // friend
    friend ostream &print(ostream&, const Sales_data&);
    friend istream &read(istream&, Sales_data&);
    public:
    // constructor
    Sales_data() = default;
    Sales_data(const string &s): bookNo(s) {}
    Sales_data(const string &s, unsigned u, double d):
        bookNo(s), units_sold(u), revenue(u*d) {}
    Sales_data(istream &is);

    string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    private:
    inline double avg_price() const;
    // member data
    string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;
};

// nonmember functions of Sales_data
Sales_data add(const Sales_data&, const Sales_data&);
ostream &print(ostream&, const Sales_data&);
istream &read(istream&, Sales_data&);
