#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "reproducible.h"

namespace lz77
{

struct LzConfig
{
    size_t buffer_capacity;
    size_t ls;
    size_t radix;
    char zero;
};

class Lz77
{
    constexpr static LzConfig st_lz_config = {18, 8, 3, '0'};

    public:
        Lz77(LzConfig cfg, std::string symbols);
        std::string encode(std::string s, LzConfig cfg = st_lz_config);
        std::string decode(std::string s, LzConfig cfg = st_lz_config);

    private:
        size_t buffer_capacity;
        size_t radix;
        size_t ls;
        std::string alpha;
        LzConfig lz_config;
        std::vector<char> buffer;
};

Lz77::Lz77(LzConfig cfg, std::string symbols)
{
    buffer_capacity = cfg.buffer_capacity;
    ls = cfg.ls;
    radix = cfg.radix;
    lz_config = cfg;
    alpha = symbols;
}

std::string Lz77::encode(std::string s, LzConfig cfg)
{
    lz_config = cfg;
    auto prefix = lz_config.buffer_capacity - lz_config.ls;
    buffer.clear();
    buffer.insert(buffer.begin(), prefix, lz_config.zero);
    // 1. initialization, set B1
    for (size_t i = 0; i < lz_config.ls; i++)
    {
        buffer.push_back(s[i]);
    }
    size_t point = lz_config.ls;
    std::string encoded{""}; 
    // 2. set Si and 4. loop
    while (point <= s.length())
    {
        std::string bi(buffer.begin(), buffer.end());
        std::cout << bi  << " prefix: " << prefix << std::endl;
        reprod::L r = reprod::max_extension(bi, prefix);
        auto li = r.length;
        auto pi = r.pos;
        std::cout << "pi: " << pi << " li: " << li << std::endl;
        std::string ci1 = reprod::radix_alpha(alpha, pi, prefix); 
        std::string ci2 = reprod::radix_alpha(alpha, li, lz_config.ls);
        std::string ci3(1, *(buffer.begin() + prefix + li));
        std::string ci = ci1 + ci2 + ci3;
        std::cout << ci << std::endl;
        std::cout << "ci1: " << ci1 << " ci2: " << ci2 << " ci3: " << ci3 << std::endl;
        encoded += ci;

        // 3. shift li symbols out, then feed into buffer with next li symbols in s
        for (size_t i = 0; i < li+1; i++)
        {
            buffer.erase(buffer.begin());
        }
        {
            for (size_t i = 0; i < li+1; i++)
            {
                buffer.push_back(s[point]);
                point += 1;
            }
        }
    }
    return encoded;
}

std::string Lz77::decode(std::string d, LzConfig cfg)
{
    lz_config = cfg;
    size_t index = 0;
    auto prefix = lz_config.buffer_capacity - lz_config.ls;
    buffer.clear();
    buffer.insert(buffer.begin(), prefix, lz_config.zero);
    std::string s{""};
    size_t fixed_width = std::ceil(std::log(lz_config.buffer_capacity - lz_config.ls) / std::log(lz_config.radix));
    fixed_width += std::ceil(std::log(lz_config.ls) / std::log(lz_config.radix));
    fixed_width += 1;
    while (index < d.length())
    {
        std::string di(buffer.begin(), buffer.end());
        std::string ci = d.substr(index, fixed_width);
        index += fixed_width;
        reprod::C rc = reprod::radix_alpha_decode(ci, lz_config.buffer_capacity, lz_config.ls, lz_config.radix, alpha); 
        for (size_t i = 0; i < rc.li - 1; i++)
        {
            buffer.push_back(buffer[rc.pi - 1]);
            buffer.erase(buffer.begin());
        }
        buffer.push_back(rc.c[0]);
        buffer.erase(buffer.begin());
        std::string si(buffer.end() - rc.li, buffer.end());
        s += si;
    }
    return s;
}

} // namespace lz77
