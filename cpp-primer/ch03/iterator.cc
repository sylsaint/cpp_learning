#include<iostream>
#include<vector>
#include<string>

using std::vector;
using std::string;

int main()
{
   vector<string> vs(20, "CC");
   for(auto it = vs.begin(); it != vs.end(); ++it)
   {
       std::cout << *it << " : " << it->size() << std::endl;
   }
   return 0;
}
