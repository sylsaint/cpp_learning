#include<iostream>
#include<string>

using namespace std;

const string &shortStr(const string &s1, const string &s2)
{
    return s1.size() < s2.size() ? s1 : s2;
};

const string &errorStr()
{
    string s1{""};
    if(!s1.empty())
        return s1;
    return "hehe";
};

int main()
{
    cout << shortStr("sunshine", "sunyonglu") << endl;
    cout << errorStr() << endl;
    return 0;
}
