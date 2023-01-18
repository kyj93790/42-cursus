#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <cstdint>
# include "Data.hpp"

class Serializer {
	public:
		Serializer();
		Serializer(const Serializer& serializer);
		~Serializer();
		const Serializer& operator=(const Serializer& serializer);
		uintptr_t serialize(Data *ptr);
		Data* deserialize(uintptr_t raw);
};

#endif