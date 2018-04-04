#include<algorithm>
#include<vector>
#include<string>
#include "priest.h"

class Ballot {
    public:
        Ballot(std::vector<Priest>&);
        std::vector<Priest> qrm;
        std::string dec;
        std::vector<Priest> vot;
        unsigned long bal;
        // member functions
        bool successful() const;

};

Ballot::Ballot(std::vector<Priest> &vp)
{
    for(auto &p : vp)
        qrm.push_back(p);
}

bool Ballot::successful() const
{
    return std::equal(qrm.begin(), qrm.end(), vot.begin(), vot.end());
}
