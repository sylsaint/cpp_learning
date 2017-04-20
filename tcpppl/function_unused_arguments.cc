#include<iostream>

void largest(int*, int*, int*);

void largest(int* p, int* q, int*)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

int main() {
    int a = 4;
    int b = 2;
    int* p1 = &a;
    int* p2 = &b;
    largest(p1, p2, p2);
    return 0;
}
