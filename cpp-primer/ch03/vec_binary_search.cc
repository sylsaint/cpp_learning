#include<iostream>
#include<vector>

using std::vector;
using std::cin;
using std::cout;

int main()
{
    vector<int> vi;
    int n;
    int sought;
    cin >> sought;
    while(cin >> n) {
        vi.push_back(n);
    }
    auto beg = vi.begin();
    auto end = vi.end();
    auto mid = beg;
    while (mid != end) {
        if (*mid == sought) {
            cout << sought << " has been found" << std::endl;
            break;
        }
        else if (*mid < sought)
           beg = mid + 1;
         else
           end = mid;
       mid = beg + (end - beg)/2;
    }
    if (mid == end) {
        cout << "no such member: " << sought << std::endl;
    }
    return 0;
}
