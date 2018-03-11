#include<iostream>

using namespace std;

int main()
{
    int c = 42;
    int n;
    while (cin >> n)
    {
        if (n == c)
        {
            break;
        }
    }
    return 0;
}
