#include "lz77.h"

int main() {
    lz77::LzConfig lc = {18, 9, 3};
    lz77::Lz77 lz = lz77::Lz77(lc);
    return 0;
}
