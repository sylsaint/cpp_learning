#include<vector>
#include<string>

using std::string;
using std::vector;

int main()
{
    vector<int> p;
    for (int i = 0; i < 10; ++i)
        p.push_back(i);
    // c++11 standard list initializer
    vector<string> svc = {"A", "B", "C"};
    vector<vector<string>> file;
    return 0;
}
