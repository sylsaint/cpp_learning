#include<iostream>
#include "extern_var.h"

using namespace std;

int main()
{
    extern int UNIVERSE;
    cout << UNIVERSE << endl;
    return 0;
}
