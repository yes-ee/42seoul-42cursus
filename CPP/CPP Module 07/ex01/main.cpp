#include "iter.hpp"
#include <string>

int main() {
	const int arr[4] = {1, 2, 3, 4};
	std::string s[3] = {"i", "want", "banana"};
	char c[7] = "hungry";
	float f[7] = {-1.1, -2.3, -3.5, -4.9, 5.1, 6.3, 0};
	double d[7] = {-1.1, -2.3, -3.5, -4.9, 5.1, 6.3, 0};

	iter(arr, 4, print);
	std::cout << std::endl;

	iter(c, 7, print);
	std::cout << std::endl;

	iter(s, 3, print);
	std::cout << std::endl;

	iter(f, 7, print);
	std::cout << std::endl;

	iter(d, 7, print);
	std::cout << std::endl;

	return 0;
}