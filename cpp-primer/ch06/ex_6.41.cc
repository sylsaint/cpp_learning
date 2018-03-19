#include<iostream>

using namespace std;

char *init(int ht, int wd = 20, char backgrnd = '');

// error

init();

// ok
init(24, 10);

// may be not programmer's intent
init(15, '*');

int main()
{
    return 0;
}
