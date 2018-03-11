#include<iostream>

using namespace std;

int main()
{
    int x[10], *p = x;
    // 10
    cout << sizeof(x)/sizeof(*x) << endl;
    // 2 sizeof(p) return pointer size 
    cout << sizeof(p)/sizeof(*p) << endl;
    return 0;
}
