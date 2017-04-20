#include<iostream>

int* f(int* fst, int* lst, int v)
{
    std::cout << "in f function, pointers are copied" << std::endl;
    std::cout << "&fst == " << &fst << ", &lst == " << &lst << std::endl;
    std::cout << "fst == " << fst << ", lst == " << lst << std::endl;
    while(fst != lst && *fst != v)
    {
        ++fst;
    }
    return fst;
}

void g(int* p, int*q)
{
    std::cout << "in g function, pointers are copied" << std::endl;
    std::cout << "&p == " << &p << ", &q == " << &q << std::endl;
    std::cout << "p == " << p << ", q == " << q << std::endl;
    int* pp = f(p, q, 10);
}

int main()
{
    int a[10] {1, 2, 5, 10, 9, 8, 7};
    int* p = a;
    int* q = p+9;
    std::cout << "initialized pointers" << std::endl;
    std::cout << "&p == " << &p << ", &q == " << &q << std::endl;
    std::cout << "p == " << p << ", q == " << q << std::endl;
    g(p, q);
}
