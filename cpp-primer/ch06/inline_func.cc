#include<iostream>

using namespace std;


inline const string &shortString(const string &s1, const string &s2)
{
    return (s1.size() < s2.size()) ? s1 : s2;
}

int main()
{
    cout << shortString("sunyonglu", "biailing") << endl;
    return 0;
}
