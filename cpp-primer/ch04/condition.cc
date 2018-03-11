#include<iostream>

using namespace std;

int main()
{
    int i = 1, j = 2;
    (i < j ? i : j) = 5;
    cout << i << endl;
    return 0;
}
