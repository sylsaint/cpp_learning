#include<iostream>

template<class T>
void f1(std::initializer_list<T> t)
{
    std::cout << "initializer_list" << std::endl;
}


struct S {
    int a;
    std::string s;
};

void f2(const S& s)
{
}

template<class T, int N>
void f3(T(&r)[N])
{
    std::cout << "reference T == " << r << std::endl;
}

void f4(const int&& i)
{
    std::cout << "int == " << i << std::endl;
}

void g()
{
    f1({1,2,3,4});  // T is int and the initializer_list has size() 4
    f2({1, "MKS"}); // f2(S{1, "MKS"})
    f3({1,2,3,4});  // T is int and N is 4
    f4({1});        // f4(int{1})        
}

int main()
{
    g();
}
