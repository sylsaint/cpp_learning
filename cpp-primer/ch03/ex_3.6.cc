#include<iostream>
#include<string>

using std::string;

int main()
{
    string s(20, 'a');
    std::cout << "source string: " << s << std::endl;
    for(auto &c: s)
        c = 'X';
    std::cout << "target string: " << s << std::endl;
    return 0;
}
