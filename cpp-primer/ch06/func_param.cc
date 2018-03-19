#include<iostream>
#include<string>

using namespace std;

bool pf(const string& s1, const string& s2)
{
    return s1.size() < s2.size();
}

typedef bool Func(const string &, const string &);
typedef decltype(pf) Func2;

string useBigger(const string& s1, const string& s2, Func)
{
    if(pf(s1, s2))
        return s2;
    return s1;
}

int main()
{
    string s1{"sunyonglu"}, s2{"biailing"};
    cout << useBigger(s1, s2, pf) << endl;
    return 0;
}
