#include<iostream>
#include<vector>

using namespace std;

struct L {
    int pos;
    int length;
};

L max_producible(vector<L> vl)
{
    auto p = vl.begin();
    for(auto begin = vl.begin(); begin != vl.end(); begin++)
    {
        if(begin->length >= p->length) {
            p = begin;
        }
    }
    return *p;
}

L max_extension_length(string s1, int index)
{
    vector<L> vl;
    for(int i = 0; i < index; i++)
    {
        L nl = {i+1, 0};
        int ln = 0;
        using ssize = string::size_type;
        ssize cur = i, cmp = index;
        do {
            if(s1[cur] == s1[cmp])
            {
                ln += 1;
            } else {
                break;
            }

        } while(cur++ && cmp++ && cmp < s1.length());
        nl.length = ln;
        vl.push_back(nl);
    }
    return max_producible(vl);
}


int main() {
    string s1 = "000000000001010210";
    L r = max_extension_length(s1, 9);
    cout << r.pos << ": " << r.length << endl;
    return 0;
}

