#include "lz77.h"
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream binary_file("input.txt");
    std::string binary_string;
    binary_file >> binary_string;
    binary_file.close();
    lz77::LzConfig lc = {18, 9, 2, '0'};
    lz77::Lz77 lz = lz77::Lz77(lc, "01");

    string s{"001010210210212021021200"};
    // string d{"22021211022021202220"};

    cout << "before compression: " << binary_string.length() << " : " << s << endl;
    string r = lz.encode(binary_string, lc);
    cout << "after compression: " << r.length() << " : " << r << endl;
    string d = lz.decode(r, lc);
    cout << "Is equal after decoding ? " <<  (d == s ? "true" : "false") << endl;
    return 0;
}
