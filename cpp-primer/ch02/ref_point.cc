#include<iostream>

using namespace std;

int main()
{
    int i = 42;
    int *p = &i;
    int *&r = p;
    cout << r << endl;
    cout << *r << endl;
    return 0;
}
