#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main() {
	std::vector<int> v;
	std::list<int> l;
	std::deque<int> d;

	for (int i = 0; i < 5; i++) {
		v.push_back(i);
		l.push_back(i);
		d.push_back(i);
	}

	try {
		std::cout << std::distance(v.begin(), easyfind(v, 1)) << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << std::distance(l.begin(), easyfind(l, 0)) << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << std::distance(d.begin(), easyfind(d, 3)) << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}