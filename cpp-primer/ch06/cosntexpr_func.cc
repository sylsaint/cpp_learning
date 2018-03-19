#include<iostream>

using namespace std;

constexpr int new_sz() { return 42; };

constexpr int sz = new_sz();

int main()
{
    cout << "new_sz(): " << new_sz() << endl;
    cout << "sz: " << sz << endl;
    return 0;
}
