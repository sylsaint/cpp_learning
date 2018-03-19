#include<iostream>
#include<string>

using namespace std;

string read();
void print(const string&);
void print(double);
void Foobar(int ival)
{
    bool read = false; // hides the declaration of read
    string s = read(); // error, read is a bool variable

    void print(int);
    print("Value: ");
    print(ival);
    print(3.14);
};

int main()
{
    return 0;
}
