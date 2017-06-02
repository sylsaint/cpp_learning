#include<iostream>
#include<vector>

using namespace std;

// some of most effective resource management in c++ rely on constructors/destructor pair

struct Tracer {
    string mess;
    Tracer(const string& s) :mess{s} { std::cout << mess << std::endl; };
    ~Tracer() { std::cout << "~" << mess << std::endl; };
};

void f(const vector<int>& v) {
    Tracer tr{"in f()\n"};
    for(auto x : v) {
        Tracer tr {string{"v loop "}+to_string(x)+'\n'};
    }
}

int main() {
    f({2,3,5});
    return 0;
}
