#include<iostream>

using some_type = int;

class X {
    X(some_type);           // ordinary construtor
    X();                    // default constructor
    X(const X&);                  // copy constructor
    X(X&&);                 // move constructor
    X& operator=(const X&); // copy assignment
    X& operator=(X&&);      // move assignment
    ~X();                   // destructor
};

// there are five situations where an object is copied or moved
// 1. as the source of an assignment
// 2. as an object initializer
// 3. as a function argument
// 4. as a function return value
// 5. as an exception
