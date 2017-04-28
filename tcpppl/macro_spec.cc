#include<iostream>

#define CONCAT_NAME(a, b) a##b
#define printx(x) std::cout << #x " = " << x << '\n';

int CONCAT_NAME(print, name) ()
{
    std::cout << "concat names" <<std::endl;
    return 0;
}

int main() {
    printname();
    int a = 7;
    std::string s = "asdf";
    printx(a);
    printx(s);
    return 0;
}
