#ifndef ITER_HPP
# define ITER_HPP

# include <cstdlib>
# include <iostream>

template<typename T>
void up(T &a) {
	a = a + 1;
}

template<typename T>
void print(T &a) {
	std::cout << a << ' ';
}

template<typename T>
void iter(const T *arr, size_t len, void (*f)(const T &t)) {
	for (size_t i=0; i<len; i++) {
		f(arr[i]);
	}
}

template<typename T>
void iter(T *arr, size_t len, void (*f)(T &t)) {
	for (size_t i=0; i<len; i++) {
		f(arr[i]);
	}
}

#endif