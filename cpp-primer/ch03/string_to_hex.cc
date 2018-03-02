#include<iostream>
#include<string>

using std::string;

int main()
{
    const string hexdigits = "0123456789ABCDEF";
    std::cout << "Enter a series of numbers between 0 and 15"
        << "separated by spaces, hit enter when you finished"
        << std::endl;
    string result;
    string::size_type n;
    while(std::cin >> n)
        if (n < hexdigits.size())
            result += hexdigits[n];
    std::cout << "Your hex number is: " << result << std::endl;
    return 0;
}
