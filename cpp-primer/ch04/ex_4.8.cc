#include<iostream>
#include<string>

using namespace std;

int main()
{
    const char *ch = "Hello, world";
    if (ch && *ch) {
        cout << *ch << endl;
    }
    return 0;
}
