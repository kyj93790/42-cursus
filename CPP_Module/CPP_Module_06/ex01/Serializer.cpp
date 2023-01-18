#include "Serializer.hpp"

Serializer::Serializer() {

}

Serializer::Serializer(const Serializer& serializer) {
	(*this) = serializer;
}

Serializer::~Serializer() {

}

const Serializer& Serializer::operator=(const Serializer& serializer) {
	(void)serializer;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr) {
	uintptr_t ret;

	ret = reinterpret_cast<uintptr_t>(ptr);
	return (ret);
}

Data* Serializer::deserialize(uintptr_t raw) {
	Data *ret;

	ret = reinterpret_cast<Data *>(raw);
	return (ret);
}