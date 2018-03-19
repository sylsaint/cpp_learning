#include<iostream>
#include<string>

using namespace std;

class Tree
{
    public:
        Tree(string s = "");
        Tree(istream &is = cin); 
};


int main()
{
    Tree t();
    return 0;
}
