#include<iostream>

using namespace std;

int main()
{
    int i = 10, j = 5;
    unique_ptr<int> p(new int(10));
    unique_ptr<int> p1(new int(20));
    cout << *p << endl;
    p.reset(p1.release());
    cout << *p << endl;
    return 0;
}
