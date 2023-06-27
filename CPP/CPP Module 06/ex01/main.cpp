#include "Serializer.hpp"

int main() {
	Data d;
	Data *pd;
	uintptr_t up;

	d.str = "hello";
	std::cout << "Data str : " << d.str << std::endl;

	up = Serializer::serialize(&d);
	pd = Serializer::deserialize(up);

	std::cout << "Check str : " << pd->str << std::endl;
}