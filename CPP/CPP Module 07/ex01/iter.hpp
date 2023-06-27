#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void iter(T* array, size_t length, void (*fp)(T&)) {
	for (size_t i = 0; i < length; i++) {
		fp(array[i]);
	}
}

template<typename T>
void print(T& element) {
	std::cout << element << std::endl;
}

#endif
