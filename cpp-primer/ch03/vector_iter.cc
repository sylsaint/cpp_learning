#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> vi = {1,2,3,4,5,6,7,8,9};
    for(auto &i: vi) {
        i *= i;
        cout << i << endl;
    }
    for(auto i: vi) {
        cout << i << endl;
    }
    return 0;
}

