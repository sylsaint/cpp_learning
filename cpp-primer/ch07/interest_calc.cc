#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    const int deposit = 1;
    const int cnt = 5;
    const int t = 19;
    const double rate = 0.06;
    double sum = 0.0;
    for (int i = 1; i != cnt + 1; ++i)
    {
        sum +=  deposit * pow(1 + rate, t - i);
    }
    cout << "total revenue: " << sum << endl;
    return 0;
}
