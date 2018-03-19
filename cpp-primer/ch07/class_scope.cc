#include<iostream>
#include "screen.h"

using namespace std;

int main()
{
    Screen::pos ht = 10, wd = 5;
    Screen scr(ht, wd, 'c');
    Screen *p = &scr;
    char c = p->get();
    cout << c << endl;
    return 0;
}
