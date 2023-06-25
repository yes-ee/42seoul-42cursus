#include "Serializer.hpp"

int main() {
	Data d;
	Data *pd;
	uintptr_t up;

	d.str = "hello";

	up = Serializer::serialize(&d);
	pd = Serializer::deserialize(up);

	std::cout << pd->str << std::endl;
}