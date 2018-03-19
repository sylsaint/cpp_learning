#include<string>
#include "person.h"


std::string Person::getName() const
{
    return name;
}
std::string Person::getAddr() const
{
    return address;
}

std::istream &read(std::istream &is, Person &p)
{
    is >> p.name >> p.address;
    return is;
}

std::ostream &print(std::ostream &os, Person &p)
{
    os << "name: " << p.getName() << ", addr: " << p.getAddr();
    return os;
}
