#include<iostream>
#include<vector>
#include "priest.h"
#include "ballot.h"

using namespace std;

int main()
{
   vector<Priest> vp;
   for(int i = 0; i < 10; i++)
   {
       Priest p(string("") + to_string(i));
       vp.push_back(p);
   }
   Ballot b{vp};
   for(auto &p : b.qrm)
       cout << p.name << endl;
   cout << "successful: " << (b.successful() ? "true" : "false") << endl;
}
