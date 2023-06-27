#include "iter.hpp"

int main() {
	int arr[4] = {1, 2, 3, 4};

	iter(&arr, 4, print);

	return 0;
}