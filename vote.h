#include<vector>
#include "ballot.h"
#include "priest.h"

class Vote {
    public:
        decltype(Ballot::bal) bal;
        Priest pst;
        decltype(Ballot::dec) dec;
};

class Votes {
    public:
        Votes(std::vector<Ballot> b) { ballots = b; };
        std::vector<Ballot> ballots;
};

class MaxVote {
    public:
        MaxVote(decltype(Ballot::bal), Priest, std::vector<Ballot>); 
        MaxVote(decltype(Ballot::bal), decltype(Ballot::vot), std::vector<Ballot>); 
};

