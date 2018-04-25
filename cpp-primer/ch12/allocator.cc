#include<memory>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

int main()
{
    allocator<string> alloc;
    auto const p = alloc.allocate(10);
    auto q = p;
    alloc.construct(q++);
    alloc.construct(q++, 10, 'c');
    alloc.construct(q++, "hi");
    while(q != p)
        alloc.destroy(--q); // q points one past "hi"
    alloc.deallocate(p, 10);

    // copy
    vector<int> vi{1,2,3,4,5};
    allocator<int> ai;
    auto const pi = ai.allocate(vi.size()*2);
    auto qi = uninitialized_copy(vi.begin(), vi.end(), pi);
    uninitialized_fill_n(qi, vi.size(), 42);
    while(qi != pi)
        cout << *--qi << endl;
    ai.deallocate(pi, vi.size()*2);
    return 0;
}
