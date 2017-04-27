#include<iostream>

void f(int x = 7);
void f(int = 7);
void f(int = 8);

int main() {
    return 0;
}
