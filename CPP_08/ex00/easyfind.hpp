#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <iterator>
#include <iostream>
#include <algorithm>

class NotFoundException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Element not found";
		}
};

template<typename T>
void easyfind(T &container, int to_find) {
	typename T::iterator it = std::find(container.begin(), container.end(), to_find);
	if (it == container.end())
		throw NotFoundException();
	else 
		std::cout << "Found " << to_find << " in position " 
				  << std::distance(container.begin(), it) << std::endl;
}

#endif