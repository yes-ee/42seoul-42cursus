#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <exception>

Base* generator(void) {
	Base* ret;
	std::srand(std::time(NULL));
	int type = rand() % 3;
	if (type == 0) {
		std::cout << "A created" << std::endl;
		ret = new A();
	}
	else if (type == 1) {
		std::cout << "B created" << std::endl;
		ret = new B();
	}
	else {
		std::cout << "C created" << std::endl;
		ret = new C();
	}
	return ret;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "pointer A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "pointer B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "pointer C" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "reference A" << std::endl;
	}
	catch (std::exception& e) {
	}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "reference B" << std::endl;
	}
	catch (std::exception& e) {
	}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "reference C" << std::endl;
	}
	catch (std::exception& e) {
	}
}

int main() {
	Base* base = generator();
	identify(base);
	identify(*base);

	delete base;
	return 0;
}