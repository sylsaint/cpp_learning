#include<iostream>
#include "pds_0n_1n.h"

using namespace std;

CFL_0n_1n::CFL_0n_1n() {
}

CFL_0n_1n::~CFL_0n_1n() {
    seq = nullptr;
}

bool CFL_0n_1n::accept() {
    return accepted;
}

void CFL_0n_1n::consume(vector<int> sequence) {
    vector<int>::iterator i;
    int stop = 0;
    for(i = sequence.begin(); i != sequence.end(); ++i) {
        if(*i == 0) {
            cfl_stack.push(*i);
        } else {
            if(cfl_stack.empty()) {
                accepted = false;
                stop = 1;
                break;
            } else {
                cfl_stack.pop();
            }
        }
    }
    if(!cfl_stack.empty()) {
        accepted = false;
    } else if(stop == 0) {
        accepted = true;
    }
}

int main() {
    vector<int> g1;
    g1.push_back(0);
    g1.push_back(0);
    g1.push_back(1);
    g1.push_back(1);
    CFL_0n_1n _0n1n;
    _0n1n.consume(g1);
    cout << _0n1n.accept() << endl;
    return 0;
}
