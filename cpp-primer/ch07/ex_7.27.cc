#include<iostream>
#include "screen.h"

using namespace std;

int main()
{
    Screen myScreen(5, 3, 'X');
    myScreen.move(1, 2).set('c').display(cout);
    cout << endl;
    myScreen.display(cout);
    cout << endl;
    return 0;
}
