#include<iostream>

using namespace std;

class PrintString {
    public:
        PrintString(ostream &o=cout, char c=' '): os(o), sep(c) {}
        void operator()(const string &s) { os << s << sep; }
    private:
        ostream &os;
        char sep;
};

int main()
{
    PrintString printer;
    string s{"yonglu.syl"};
    printer(s);
    PrintString errors(cerr, '\n');
    errors(s);
    return 0;
}
