#include<iostream>

// the same name with class name can only be constructor, which has not return type
//
// class X {
//   X();
//   void X(); error
//   int X; error
//   enum S {}; error

// class initialization must establish class invariant
// something must be hold whenever a member function is called

class Vector {
    public:
        Vector(int n);
    private:
        double* elem; //elem points to an array of sz doubles
        int sz;       //sz is non-negative
};


