#include<cstring>
#include<iostream>

int stringlen(const char*);

int stringlen(const char* s)
{
    std::cout << s << " length == " << std::strlen(s) << std::endl;
    return std::strlen(s);
}

void f()
{
    char v[] = "Annemarie";
    int i = stringlen(v);
    int j = stringlen("Nicholas");
}

int main()
{
    f();
    return 0;
}
