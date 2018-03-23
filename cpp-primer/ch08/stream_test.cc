#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

int main()
{
    ofstream out1, out2;
    int j;
    cin >> j;
    auto old_state = cin.rdstate();
    cout << iostream::badbit << endl;
    cout << cin.bad() << endl;
    cout << cin.fail() << endl;
    cin.setstate(old_state);

    cout << iostream::badbit << endl;
    cout << cin.bad() << endl;
    cout << cin.fail() << endl;
    return 0;
}
