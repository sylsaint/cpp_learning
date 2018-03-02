#include<iostream>
#include<string>
#include<cctype>

using std::string;

int main()
{
    string s(10, 'a');
    decltype(s) x = "101";
    char c = 'a';
    std::cout << "isalnum(c): " << c << " " << isalnum(c) << std::endl;
    std::cout << "isalpha(c): " << c << " " << isalpha(c) << std::endl;
    std::cout << "iscntrl(c): " << c << " " << iscntrl(c) << std::endl;
    std::cout << "isdigit(c): " << c << " " << isdigit(c) << std::endl;
    std::cout << "isxdigit(c): " << c << " " << isxdigit(c) << std::endl;
    if (!s.empty())
        s[0] = toupper(s[0]);
    std::cout << s << std::endl;
    string s1("some thing");
    for (decltype(s1.size()) index = 0; index != s1.size() && !isspace(s1[index]); ++index)
        s1[index] = toupper(s1[index]);
    std::cout << s1 << std::endl;
    return 0;
}
