#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<void*> vc;
    int i = 10;
    double d = 25.0;
    void *pi = &i;
    void *pd = &d;
    vc.push_back(pi);
    vc.push_back(pd);
    for(auto beg = vc.begin(); beg != vc.end(); ++beg)
        cout << *beg << endl;
    return 0;
}
