#include<iostream>
#include "concrete_class.cc"

using namespace Chrono;

// naturally, member function definition must be provided somewhere

Date::Date(int dd, Month mm, int yy) :d{dd}, m{mm}, y{yy} {
}
