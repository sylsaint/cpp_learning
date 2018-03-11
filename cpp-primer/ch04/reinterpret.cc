#include<iostream>

using namespace std;

int main()
{
    int d = 97;
    int *ip = &d;
    char *pc = reinterpret_cast<char*>(ip);
    cout << *pc << endl;
    return 0;
}

