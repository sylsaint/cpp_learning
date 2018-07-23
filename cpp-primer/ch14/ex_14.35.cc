#include<iostream>
#include<string>

using namespace std;

class PrintString {
    public:
        PrintString() {}
        const string operator()(istream&);
    private:
        string s{""};
};

const string PrintString::operator()(istream &i) {
    i >> s;
    if (i) {
        return s;
    }
    return string("");
}

int main()
{
    PrintString printer;
    cout << printer(cin) << endl;
    return 0;
}
