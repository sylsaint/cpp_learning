#include<iostream>

using namespace std;

void print(int i, int j)
{
    cout << "int: " << i << " and " << j << endl;
};

void print(double a, double b)
{
    cout << "double: " << a << " and " << b << endl;
}

int main()
{
    print(10, 25.4);
    print(24.1, 5);
    return 0;
} 
