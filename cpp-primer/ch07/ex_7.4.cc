#include<iostream>
#include<string>
#include "person.h"

using namespace std;

int main()
{
    Person p;
    Person *pt = &p;
    pt->name = "sunyonglu";
    pt->address = "younengkejiyuan";
    cout << pt->getName() << endl;
    cout << pt->getAddr() << endl;
    return 0;
}
