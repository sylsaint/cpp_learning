#include<fstream>

using namespace std;

int main()
{
    ofstream out;
    out.open("ofstream.txt");
    out << "I am your friend\n";
    out.close();
    out.open("ofstream.txt", ofstream::app);
    out << "I am your father\n";
    out.close();
    return 0;
}
