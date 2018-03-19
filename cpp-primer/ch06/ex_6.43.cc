#include<iostream>
#include<string>

using namespace std;

string make_plural(size_t ctr, const string &word, const string &end = "s")
{
    return (ctr > 1) ? word + end : word;
};

int main()
{
    cout << make_plural(10, "name") << endl;
    return 0;
}
