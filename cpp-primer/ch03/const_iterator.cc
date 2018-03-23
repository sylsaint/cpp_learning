#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> vi{1,2,3,4,5};
    vector<int>::const_iterator it;
    int *const p = &*vi.begin();
    cout << *p << endl;
    for(it = vi.begin(); it != vi.end(); ++it)
        cout << *it << endl;
    return 0;
}
