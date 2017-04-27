#include<iostream>
#include<cstdio>

extern void error(const int& p ...)
{
    std::cout << p << std::endl;
}

int main(int argc, char* argv[])
{
    std::cout << "argc == " << argc << std::endl;
    switch(argc) {
        case 1:
            error(0, argv[0], nullptr);
            break;
        case 2:
            error(0, argv[0], argv[1], nullptr);
            break;
        default:
            error(1, argv[0], "with", "test", "arguments", nullptr);
    }
}

