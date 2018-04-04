#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<iostream>

using namespace std;

// declaration
bool isShorter(const string&, const string&);

void elimDups(vector<string> &words)
{
    stable_sort(words.begin(), words.end(), isShorter);
    vector<string>::iterator end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

// defninition
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    vector<string> vs;
    string s;
    getline(cin, s);
    istringstream is{s};
    while(is >> s) {
        vs.push_back(s);
    }
    for(const auto &it: vs)
        cout << it << " "; 
    cout << endl;
    elimDups(vs);
    for(const auto &it: vs)
        cout << it << " "; 
    cout << endl;
    return 0;
}
