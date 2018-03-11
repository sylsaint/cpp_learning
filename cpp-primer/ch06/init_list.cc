#include<iostream>
#include<vector>
#include<initializer_list>

using namespace std;

void print_lst(initializer_list<int> lst)
{
    for(auto beg = lst.begin(),end = lst.end(); beg != end; ++beg)
    {
        cout << *beg << endl;
    }
};

void print_lst(vector<int> lst)
{
    for(auto beg = lst.begin(),end = lst.end(); beg != end; ++beg)
    {
        cout << *beg << endl;
    }
};

int main()
{
    initializer_list<int> it = {1,2,3,4,5};
    vector<int> vt = {1,2,3,4,5};
    print_lst({1,2,3,4,5});
    print_lst({1,2,3,4,5});
    return 0;
}
