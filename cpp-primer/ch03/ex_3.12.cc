#include<iostream>
#include<vector>
#include<string>

using std::vector;
using std::string;

int main()
{
    vector<vector<int>> vvi;
    vector<string> vs = vvi; // error,incompatible type
    vector<string> svec(10, "null"); // ok
    return 0;
}
