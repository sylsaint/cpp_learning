#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> v1{1,2,3,4};
    vector<int> v2{5,6,7};
    vector<int> v3{9,0,8,7,11};
    v1 = v2;
    v1 = v3;
    for(const auto &i : v1)
        cout << i << endl;
    for(auto beg = v1.begin(); beg != v1.end(); ++beg)
        cout << *beg << endl;
    return 0;
}
