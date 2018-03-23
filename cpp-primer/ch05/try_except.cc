#include<stdexcept>
#include<vector>
#include<iostream>

using namespace std;

int main()
{
    vector<int> vi{1,3,4};
    auto beg = vi.begin();
    try {
        int i;
        cout << "enter index:" << endl;
        cin >> i;
        beg += i;
        int k = *beg;
        cout << "output number: " << k << endl;
    } catch (exception err) {
        cout << "overflow error" << endl;
    }
    return 0;
}
