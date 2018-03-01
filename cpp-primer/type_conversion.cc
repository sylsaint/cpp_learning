#include<iostream>

int main()
{
	bool b = 42;            // b is true
	std::cout << b << std::endl;
	int i = b;              // i has value 1
	std::cout << i << std::endl;
	i = 3.14;               // i has value 3
	std::cout << i << std::endl;
	double pi = i;          // pi has value 3.0
	std::cout << pi << std::endl;
	unsigned char c = -1;   // assuming 8-bit chars, c has value 255
	std::cout << "c: " << c << std::endl;
	signed char c2 = 256;   // assuming 8-bit chars, the value of c2 is undefined”
	std::cout << "c2: " << c2 << std::endl;
	// test implicit type conversion
	// below is int to unsigned
	int m = -42;
	unsigned int n = 24;
	std::cout << m + m << std::endl;
	std::cout << m + n << std::endl; // if 32bits-int, it will output 4294967264
	// unsigned int arithmatic
	unsigned int u1 = 40, u2 = 10;
	std::cout << u1 - u2 << std::endl; // ok, output 30
	std::cout << u2 - u1 << std::endl; // ok, but result will be wrapped around
	// unsigned loop
	unsigned loop = 10;
	while (loop > 0) {
		std::cout << --loop << std::endl;
	}
	return 0;
}

