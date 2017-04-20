#include<iostream>

void f(int a)
{
    while(a--) {
        static int n = 0;
        int x = 0;

        std::cout << "n == " << n++ << ", x == " << x++ << std::endl;
    }
}

int main()
{
    f(3);
} 
