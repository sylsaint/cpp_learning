#include<iostream>

void swap(int*, int*);

void swap(int* p, int* q)
{
    int t = *p;
    *p = *q;
    *q = t;
}

int main() {
    int a = 10;
    int b = 20;
    int* p1 = &a;
    int* p2 = &b;
    swap(p1, p2);
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    return 0;
}
