#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main()
{
    string line, word;
    vector<PersonInfo> pv;
    while(getline(cin, line)) {
        PersonInfo p;
        istringstream record(line);
        record >> p.name;
        while(record >> word) {
            p.phones.push_back(word);
        }
        pv.push_back(p);
    }
    for(const auto &p: pv) {
        cout << p.name << endl;
    }
    return 0;
}

