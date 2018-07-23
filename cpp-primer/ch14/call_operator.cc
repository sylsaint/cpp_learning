#include<iostream>

using namespace std;

struct absInt {
    int operator()(int val) const {
        return val < 0 ? -val : val;
    }
};

int main() {
    int positive = 10;
    int negative = -10;
    int zero = 0;
    absInt absObj;
    cout << absObj(positive) << endl;
    cout << absObj(negative) << endl;
    cout << absObj(zero) << endl;
    return 0;
}
