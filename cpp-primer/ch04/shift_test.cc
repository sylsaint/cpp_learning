#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    unsigned char ch = 233;
    cout << ch << endl;
    unsigned int r = ch << 31;
    cout << r << endl;
    cout << pow(2, 31) << endl;
    return 0;
}
