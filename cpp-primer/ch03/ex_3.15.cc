#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
    string n;
    vector<string> vi;
    while (cin >> n)
        vi.push_back(n);
    cout << vi.empty() << endl; 
    return 0;
}
