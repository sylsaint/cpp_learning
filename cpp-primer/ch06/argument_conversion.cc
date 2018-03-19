#include<iostream>

using namespace std;

void calc(char* a, char* b)
{
    cout << *a << " : " << *b << end;
}

void print(int &i)
{
    cout << i << endl;
};

int main()
{
    int i = 3;
    char ch1 = 'a', ch2 = 'b';
    char *c1 = &ch1;
    char *c2 = &ch2;
    calc(c1, c2);
    print(i);
    return 0;
}
