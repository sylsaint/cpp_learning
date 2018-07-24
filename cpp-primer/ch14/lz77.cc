#include "lz77.h"
#include<string>
#include<fstream>

using namespace std;

int main() {
    ifstream binary_file("input.txt");
    std::string binary_string;
    binary_file >> binary_string;
    binary_file.close();
    lz77::LzConfig lc = {8, 4, 2, '0'};
    lz77::Lz77 lz = lz77::Lz77(lc, "01");

    string s{"001010210210212021021200"}; 
    // string d{"22021211022021202220"}; 
    
    cout << "before: " << binary_string.length() << endl;
    string r = lz.encode(binary_string, lc);
    cout << "after: " << r.length() << endl;
    // string d = lz.decode(r, lc);
    // cout << "decoded: " << d.length() << endl;
    return 0;
}
