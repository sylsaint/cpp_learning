#include<iostream>

using namespace std;

int main()
{
    int i, j, k;
    cin >> i >> j >> k;
    // < has higher precedence than !=
    // i != (j < k)
    if (i != j < k)
    {
        cout << "i != j < k: " << (i!=j<k) << endl;
    }
    return 0;
}
