#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {

	private:
		T *_data;
		unsigned int _size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &copy);
		Array &operator=(const Array &src);
		~Array();

		T  &operator[](unsigned int index);
		const T  &operator[](unsigned int index) const;
		unsigned int size() const;

		class OutOfBoundsException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Index out of bounds";
				}
		};
};

#include "Array.tpp"

#endif