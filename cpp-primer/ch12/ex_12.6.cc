#include<iostream>
#include<vector>

using namespace std;

vector<int>* make_vector()
{
    auto *p = new vector<int>();
    return p;
}

void write_vector(vector<int> *vc)
{
    int i;
    while(cin>>i)
    {
        vc->push_back(i);
    }
}

void print_vector(vector<int> *vc)
{
    for(auto beg = vc->begin(); beg != vc->end(); ++beg)
    {
        cout << *beg << endl;
    }
}

int main()
{
    auto vc = make_vector();
    write_vector(vc);
    print_vector(vc);
    delete vc;
    return 0;
}
