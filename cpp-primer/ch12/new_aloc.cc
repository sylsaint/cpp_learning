#include<iostream>

using namespace std;

int *p = new int;
int *p1 = new int();
const string *ps = new const string;
const int *pc = new const int(100);

int main()
{
    cout << "*p: " << *p << endl;
    cout << "*p1: " << *p1 << endl;
    delete pc;
    const int *pc1 = new const int(200);
    cout << "*pc: " << *pc << endl;
    return 0;
}
