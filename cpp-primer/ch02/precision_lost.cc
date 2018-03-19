#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    cout << sizeof(unsigned long long) << endl;
    cout << sizeof(float) << endl;
    cout << sizeof(int) << endl;
    float f = 0.0;
    int u = 0;
    cout << f << endl;
    long long l = pow(2, 62);
    long r = pow(2, 32);
    l -= 3;
    cout << l << endl;
    cout << l % r << endl;
    f = l;
    u = l;
    cout << f << endl;
    cout << u << endl;
    return 0;
}
