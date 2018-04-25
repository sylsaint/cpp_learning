#include "strblob_ptr.cc"
#include<iostream>
#include<string>

using namespace std;

int main()
{
    StrBlob sb;
    string s;
    while(cin >> s)
    {
        sb.push_back(s);
    }
    for(auto beg = sb.begin(); beg != sb.end(); beg.incr())
        cout << beg.deref() << endl;
    return 0;
}
