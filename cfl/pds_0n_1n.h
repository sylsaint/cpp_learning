#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class CFL_0n_1n {
    public:
        CFL_0n_1n();
        ~CFL_0n_1n();
        stack <int> cfl_stack;               
        bool accept();
        void consume(vector<int>);
    private:
        vector<int> *seq;
        bool accepted = false;
};

