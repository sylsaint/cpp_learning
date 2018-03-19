#include<string>

struct Person
{
    // friend
    friend std::istream &read(std::istream&, Person&);
    friend std::ostream &print(std::ostream&, Person&);
    public:
    // constructor
    Person() {}
    Person(std::string &n, std::string &addr):
        name(n), address(addr) {}
    // member functions
    std::string getName() const;
    std::string getAddr() const;
    private:
    // properties
    std::string name;
    std::string address;
};

std::istream &read(std::istream&, Person&);
std::ostream &print(std::ostream&, Person&);
