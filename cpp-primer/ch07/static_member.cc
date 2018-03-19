#include<iostream>

using namespace std;

class StaticMember {
    public:
        static double rate(double r = ir) { return r; };
    private:
        static double initialRate;
        static const double ir;
};

double StaticMember::initialRate = 4.9;
const double StaticMember::ir = 4.9;


int main()
{
    double r;
    r = StaticMember::rate();
    cout << r << endl;
    return 0;
}
