#pragma once
#include<string>

class Priest {
    public:
        Priest(std::string);
        bool voted;
        std::string name;
        void vote() { voted = true; };

        // operator overloading
        inline bool operator==(const Priest &rhs) const { return this->name == rhs.name; };
        inline bool operator!=(const Priest &rhs) const { return !(this->name == rhs.name); }
};

Priest::Priest(std::string s)
{
    name = s;
}
