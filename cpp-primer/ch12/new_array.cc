#include<iostream>

using namespace std;

int main()
{
    int *p = new int[9](); // value initialized
    delete [] p;
    int *p1 = new int[9]{1,2,3,4,5,6,7,8,9};
    for(auto beg = p1, end = (p1 + 9); beg != end; ++beg)
        cout << *beg << endl;
    // smart pointer
    unique_ptr<int[]> up(new int[10]());
    up.release();
    // shared pointer
    shared_ptr<int> sh(new int[10](), [](int *p) { delete [] p; });
    sh.reset();

    // allocator
    
    return 0;
}
