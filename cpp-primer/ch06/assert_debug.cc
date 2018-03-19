#include<iostream>
#include<string>
#include<cassert>

using namespace std;

int main()
{
#ifndef NDEBUG
    cerr << "Error: " << __FILE__
         << " : in function " << __func__
         << " at line " << __LINE__ << endl
         << "       Compiled on " << __DATE__
         << " at " << __TIME__ << endl
         << "       Word read was \"hehe"
         << "\":  Length too short" << endl;
#endif
    string s;
    string sought{"hehe"};
    while(cin >> s && s != sought) {};
    assert(cin);
    return 0;
}
