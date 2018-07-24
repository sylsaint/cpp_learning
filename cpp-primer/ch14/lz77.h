#pragma once
#include<string>
#include<vector>

namespace lz77 {

struct LzConfig {
    size_t buffer_capacity;
    size_t ls;
    size_t radix;
    char zero;
};

class Lz77 {
    constexpr static LzConfig st_lz_config = {18, 8, 3, '0'};
    public:
        Lz77(LzConfig cfg);
        std::string encode(std::string s, LzConfig cfg = st_lz_config);
        std::string decode(std::string s, LzConfig cfg = st_lz_config);
    private:
        size_t buffer_capacity;
        size_t radix;
        size_t ls;
        LzConfig lz_config;
        std::vector<char> buffer;
};

Lz77::Lz77(LzConfig cfg) {
    buffer_capacity = cfg.buffer_capacity;
    ls = cfg.ls;
    radix = cfg.radix;
    lz_config = cfg;
}

std::string Lz77::encode(std::string s, LzConfig cfg) {
    lz_config = cfg;
    buffer.insert(buffer.begin(), lz_config.ls, lz_config.zero);
    return "";
}

std::string Lz77::decode(std::string s, LzConfig cfg) {
    return "";
}

}
