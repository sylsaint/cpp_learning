#include<iostream>
#include "type_name.h"

int main()
{
    int i = 10, &r = i;
    auto a = r;

    std::cout << a << std::endl;
    std::cout << type_name<decltype(a)>() << std::endl;

	const int ci = i, &cr = ci;
	auto b = ci; // b is a const int
    std::cout << b << std::endl;
    std::cout << type_name<decltype(b)>() << std::endl;
	auto c = cr; //  c is a const int
    std::cout << c << std::endl;
    std::cout << type_name<decltype(c)>() << std::endl;
	auto d = &ci; // d is const int*
    std::cout << d << std::endl;
    std::cout << type_name<decltype(d)>() << std::endl;
	auto e = &cr;  // e is const int*
    std::cout << e << std::endl;
    std::cout << type_name<decltype(e)>() << std::endl;

	// deduce one type to have top-level const
	const auto f = &cr;
    std::cout << f << std::endl;
    std::cout << type_name<decltype(f)>() << std::endl;

	// auto reference
	auto &g = ci;
	// auto &h = 42; 
    // can't bind plain reference to literal
	const auto &j = 42;
    auto &n = i, *p2 = &ci;
    return 0;
}
