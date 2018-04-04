#include<iostream>
#include<string>

using namespace std;

int main()
{
    shared_ptr<int> p = make_shared<int>(20);
    auto ps = make_shared<string>(10, 's');
    auto qs{ps};
    if(p) *p = 50;
    cout << *p << endl;
    cout << *qs << endl;
    return 0;
}
