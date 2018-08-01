#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using std::vector;
using std::string;

namespace reprod {

struct L {
    size_t pos;
    size_t length;
};

struct C {
    size_t pi;
    size_t li;
    string c;
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

L max_extension(string s1, size_t index)
{
    vector<L> vl;
    for(size_t i = 0; i < index; i++)
    {
        L nl = {i, 0};
        int len = 0;
        using ssize = string::size_type;
        ssize cur = i, cmp = index;

        while(len < s1.length() - index)
        {
            if(s1[cur] == s1[cmp])
            {
                len += 1;
            } else {
                break;
            }
            cur++;
            cmp++;
        }
        nl.length = len;
        vl.push_back(nl);
    }
    return max_producible(vl);
}

/*
 * @params: string alpha represents the symbol set
 * @params: size_t n represents the input number
 * @params: size_t w means the max bits width, at least 1
 */
string radix_alpha(string alpha, size_t n, size_t bits) {
    std::string represent{""};
    auto local = n;
    auto radix = alpha.length();
    size_t w = std::ceil(std::log(bits) / std::log(radix));
    auto index = w;
    do {
       auto i = index - 1;
       size_t bit = local / std::pow(radix, i);
       // TODO: fix me, not correct exactly
       represent += alpha[bit];
       local = local % static_cast<size_t>(std::pow(radix, i));
       index--;
    } while (index != 0);
    return represent;
}

/*
 * @params: string ci represents the compressed text
 * @params: size_t n represents the bufer capacity 
 * @params: size_t ls means the max symbol width
 * @params: string alpha represents the symbol set
 */
C radix_alpha_decode(string ci, size_t n, size_t ls, size_t radix, string alpha) {
    size_t pos_width = std::ceil(std::log(n - ls) / std::log(radix));
    size_t extent_width = std::ceil(std::log(ls) / std::log(radix));
    string ci1 = ci.substr(0, pos_width);
    string ci2 = ci.substr(pos_width, extent_width);
    string ci3 = string(1, ci.back());
    size_t pi = 0;
    for(size_t i = 0; i < ci1.length(); i++)
    {
        pi += std::stoi(ci1.substr(i, 1)) * std::pow(radix, ci1.length() - i - 1);
    }
    size_t li = 0;
    for(size_t i = 0; i < ci2.length(); i++)
    {
        li += std::stoi(ci2.substr(i, 1)) * std::pow(radix, ci2.length() - i - 1);
    }
    return C{pi+1, li+1, ci3};
}

}
