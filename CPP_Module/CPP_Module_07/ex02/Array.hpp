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
		Array() : _size(0), _arr(new T[0]) { };
		Array(unsigned int n) : _size(n), _arr(new T[n]) { };
		Array(const Array& arr) {
			_size = arr._size;
			if (this != &arr) {
				_arr = new T[arr.size()];
				for (int i=0; i<_size; i++)
					_arr[i] = arr[i];
			}
		};
		~Array() {
			if (_arr) delete _arr;
		};
		Array& operator=(const Array& arr) {
			_size = arr._size;
			if (this != &arr) {
				if (_arr) delete _arr;
				_arr = new T[arr.size()];
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