#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>

template <typename T>
typename T::iterator easyfind(T container, int target) {
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), target);
	if (it == container.end()) throw std::runtime_error("Unknown target");
	return it;
}

#endif