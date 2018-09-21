#include<iostream>

using namespace std;

int tadd_ok(int x, int y)
{
    int s = x + y;
    if (x > 0 && y > 0 && s <= 0) {
        return 0;
    }
    if (x < 0 && y < 0 && s >= 0) {
        return 0;
    }
    return 1;
}

int tsub_ok(int x, int y)
{
    int s = x - y;
    if (x > 0 && y < 0 && s <=0) {
        return 0;
    }
    if (x < 0 && y > 0 && s >=0) {
        return 0;
    }
    return 1;
}

int tsub_ok_2(int x, int y)
{
    // x > 0 && y > 0 && x + y <= 0 is not the case
    // x < 0 && y < 0 && x + y >= 0 is not the case
    return tadd_ok(x ,-y);
}

int tadd_ok_2(int x, int y)
{
    int sum = x + y;
    // 2147483647 + 2 = -2147483647, -2147483647 - 2 = 2147483647
    // so (sum - x == y) always be true
    return (sum - x == y) && (sum - y == x);
}

int tadd(int x, int y)
{
    return x + y;
}

int main() {
    int max = 2147483647;
    int min = -2147483648;
    int two = 2;
    int negative = -10;
    cout << "positive overflow: " << tadd_ok(max, two) << " result: " << tadd(max, two) << endl;
    cout << "negative overflow: " << tadd_ok(min, negative) << " result: " << tadd(min, negative) << endl;

    return 0;
}
