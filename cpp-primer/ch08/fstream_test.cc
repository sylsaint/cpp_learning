#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    string s{"fstream_test.cc"};
    char cs[] = {'c', 'p', 'p'};
    char *pcs = cs;
    fstream strm(pcs);
    cout << strm.is_open() << endl;
    strm.close();
    cout << strm.is_open() << endl;
    return 0;
}
