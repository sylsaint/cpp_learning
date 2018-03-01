#include<iostream>

int main()
{
    // currentVal is the number we are counting; we'll read new values into val
    int currentVal = 0, val = 0;
    int count = 0;
    if (std::cin >> val)
        currentVal = val;
    // when encountering EOF(^+d in macOS), loop terminates
    while (std::cin >> val)
    {
        // if currentVal equals val, increment count by one
        if (currentVal == val)
            count += 1;
    }
    std::cout << currentVal << " occurs " << count << " times" << std::endl;
    return 0;
}

