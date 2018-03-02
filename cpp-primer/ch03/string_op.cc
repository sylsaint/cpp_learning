#include<iostream>
#include<string>

using std::string;

int main()
{
    string s(10, 'c'); // first counts, second char
    auto len = s.size();
    std::cout << s << " length: " << len << std::endl;
    return 0;
}
