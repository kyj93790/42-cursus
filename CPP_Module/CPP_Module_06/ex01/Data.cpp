#include "Data.hpp"

Data::Data() {

}

Data::Data(std::string id, int num): _id(id), _num(num) {

}

Data::Data(const Data& data) {
	(*this) = data;
}

Data::~Data() {

}

const Data& Data::operator=(const Data& data) {
	_num = data._num;
	return (*this);
}


std::string Data::getId() const {
	return _id;
}

int Data::getNum() const {
	return _num;
}