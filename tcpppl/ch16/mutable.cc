#include<iostream>
#include<stdlib.h>

using namespace std;

// immutability leads to comprehensible code, error detection earlier, better performance
// very useful in multithread programming
//
// const member func
// the const after argument indicates that function does not modify the state of class

class Date {
    private:
        int d, m, y;
    public:
        int get_year() const;
        int get_month() const { return m; };
        int get_day() const { return d; };
        Date(int dd = 0, int mm = 0, int yy = 0);

        void add_year(int n);
};

/* 
    int Date::get_year() const {
        return ++y;                // error: modify y
    }

    int Date::get_year() {         // error: const is part of type Date::get_year
        return y;
    }
*/


// tip: a const member functio can be invoked on const and non-const objects, a non-const function
// can be only invoked on non-const objects

// physical and logical constness

// a member function is logically const, object is const to user, but some details use can not observe
// change, this is often called logical constness.

class LogicDate {
    private:
        mutable bool cache_valid;
        mutable string cache;
        void compute_cache_value() const;
        string random_string() const;
    public:
        string string_rep() const;
};

string LogicDate::string_rep() const {
    if(!cache_valid) {
        compute_cache_value();
        cache_valid = true;
    }
    return cache;
}

void LogicDate::compute_cache_value() const {
    cache = random_string();
}

string LogicDate::random_string() const {
    char ch[10];
    for(int i = 0; i < 10; i++) {
        ch[i] = rand()*26 + 65;
    }
    string str(ch);
    return str;
}

// mutability through indirection

struct Cache {
    bool valid;
    string rep;
};

class InDate {
    private:
        void compute_cache_value() const;
        string random_string() const;
        Cache *cache;
    public:
        string string_rep() const;
        InDate();
};

string InDate::string_rep() const {
    if(!cache->valid) {
        compute_cache_value();
        cache->valid = true;
    }
    return cache->rep;
}

void InDate::compute_cache_value() const {
    cache->rep = random_string();
}

string InDate::random_string() const {
    char ch[10];
    for(int i = 0; i < 10; i++) {
        ch[i] = rand()*26 + 65;
    }
    string str(ch);
    return str;
}

InDate::InDate() {
    Cache c = Cache{false, ""};
    cache = &c;
}



int main() {
    LogicDate ld {};
    for(int i = 0; i < 10; i++) {
        cout << ld.string_rep() << endl;
    }
    InDate lid {};
    for(int i = 0; i < 10; i++) {
        cout << lid.string_rep() << endl;
    }
    return 0;
}
