#include<iostream>

const int i = 10;

const int *p = nullptr;

constexpr int *pr = nullptr;

int j = 10;

constexpr int ci = 5;

constexpr int *pj = &j;

constexpr const int *pk = &ci;

int main()
{
    return 0;
}
