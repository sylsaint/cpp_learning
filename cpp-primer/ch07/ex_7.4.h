#include<string>

struct Person
{
    // member functions
    std::string getName() const;
    std::string getAddr() const;
    // properties
    std::string name;
    std::string address;
};
