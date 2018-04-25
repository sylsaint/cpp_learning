#include<iostream>

using namespace std;

int main()
{
    int *p(new int(48));
    auto q = p;
    delete p;
    p = nullptr;
    cout << *q << endl;
    return 0;
}
