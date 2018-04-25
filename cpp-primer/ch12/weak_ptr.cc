#include<iostream>

using namespace std;

int main()
{
    shared_ptr<int> p = make_shared<int>(42);
    auto p1(p);
    shared_ptr<int> p2;
    p2 = p1;
    weak_ptr<int> wp(p);
    cout << wp.use_count() << endl;
    if (shared_ptr<int> np = wp.lock())
    {
        cout << "number: " << *np << endl;
    }
    return 0;
}
