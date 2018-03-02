#include<string>
using std::string;

int main()
{
    string s1;
    string s2 = s1;
    string s21(s1);
    string s3 = "nmh";
    string s31("nmh");
    string s4(10, 'c');
    return 0;
}
