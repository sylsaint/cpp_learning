#include<iostream>
#include<string>

using namespace std;

void print(const string&);
void print(int);
void print(float);
void print(double);

void Foobar(int ival)
{
    print("Val: ");
    print(ival);
    print(3.14); // 3.14 is default double
    print(3.14f); // 3.14f is float 
}
