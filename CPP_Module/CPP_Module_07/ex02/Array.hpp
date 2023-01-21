#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>

template <typename T>
class Array {
	private:
		int _size;
		T *_arr;
	public:
		Array() : _size(0), _arr(new(std::nothrow) T[0]) {
			if (_arr == NULL) {
				std::cerr << "Error : fail to alloc";
				std::exit(EXIT_FAILURE);
			}
		};
		Array(unsigned int n) : _size(n), _arr(new(std::nothrow) T[n]) { 
			if (_arr == NULL) {
				std::cerr << "Error : fail to alloc";
				std::exit(EXIT_FAILURE);
			}
		};
		Array(const Array& arr) {
			if (this != &arr) {
				_size = arr._size;
				_arr = new(std::nothrow) T[arr.size()];
				if (_arr == NULL) {
					std::cerr << "Error : fail to alloc";
					std::exit(EXIT_FAILURE);
				}
				for (int i=0; i<_size; i++)
					_arr[i] = arr[i];
			}
		};
		~Array() {
			delete[] _arr;
		};
		Array& operator=(const Array& arr) {
			if (this != &arr) {
				_size = arr._size;
				delete[] _arr;
				_arr = new(std::nothrow) T[arr.size()];
				if (_arr == NULL) {
					std::cerr << "Error : fail to alloc";
					std::exit(EXIT_FAILURE);
				}
				for (int i=0; i<_size; i++)
					_arr[i] = arr[i];
			}
			return (*this);
		};
		T& operator[](int index) {
			if (index < 0 || index >= size()) throw std::out_of_range("Error : out of range");
			return _arr[index];
		};
		const T& operator[](int index) const {
			if (index < 0 || index >= size()) throw std::out_of_range("Error : out of range");
			return _arr[index];
		};
		int size() const {
			return _size;
		};
};

#endif