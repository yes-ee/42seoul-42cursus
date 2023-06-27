#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>

typedef struct s_data {
	std::string str;
} Data;

class Serializer {
	private:
		Serializer();
	public:
		~Serializer();
		Serializer(const Serializer& ref);
		Serializer& operator=(const Serializer& ref);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
