#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template <typename T>
class Array {
    private:
        T* arr;
        unsigned int length;
    public:
        Array() {
            this->length = 0;
            std::cout << "Default constructor called" << std::endl;
        }
        Array(unsigned int n) {
            this->length = n;
            if (this->length != 0)
                this->arr = new T[length];
            std::cout << "N Constructor called" << std::endl;
        }
        ~Array() {
            if (this->length != 0)
                delete [] arr;
            std::cout << "Destructor called" << std::endl;
        }
		Array(const Array& ref) {
            this->length = ref.length;
            this->arr = new T[length];
            for (unsigned int i = 0; i < length; i++) {
                this->arr[i] = ref.arr[i];
            }
            std::cout << "Copy constructor called" << std::endl;
        }
		Array& operator=(const Array& ref) {
            if (this != &ref) {
                if (this->length != 0)
                    delete [] this->arr;
                this->length = ref.length;
                if (this->length != 0)
                    this->arr = new T[length];
                for (unsigned int i = 0; i < length; i++) {
                    this->arr[i] = ref.arr[i];
                }
                std::cout << "Copy assignment operator called" << std::endl;
            }
            return *this;
        }
        unsigned int size(void) const{
            return this->length;
        }

        T& operator[] (unsigned int idx) {
            if (idx < 0 || idx >= length)
                throw std::exception();
            return this->arr[idx];
        }

        const T& operator[] (unsigned int idx) const{
            if (idx < 0 || idx >= length)
                throw std::exception();
            return this->arr[idx];
        }
};

#endif
