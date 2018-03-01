int i = 10, &r = i;
auto a = r;

const int ci = i, &cr = ci;
auto b = ci; // b is a int
auto c = cr; //  c is a int
auto d = &ci; // d is const int*
auto e = &cr;  // e is const int*

// deduce one type to have top-level const
const auto f = &cr;

// auto reference
auto &g = ci;
// auto &h = 42; 
// can't bind plain reference to literal
const auto &j = 42;
// auto &n = i, *p2 = &ci;
