#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int nbr) : _maxSize(nbr) {}

Span::Span(const Span &copy) {
	*this = copy;
}

Span &Span::operator=(const Span &src) {
	if (this != &src) {
		this->_maxSize = src._maxSize;
		this->_numbers = src._numbers;
	}
	return *this;
}

Span::~Span() {}

unsigned int Span::shortestSpan() const {
	if (_numbers.size() < 2)
		throw Span::NotEnoughElementsException();
	
	std::vector<int> copy = _numbers;
	std::sort(copy.begin(),copy.end());
	unsigned int min = copy[1] - copy[0];
	for(int i = 1; i < copy.size() - 1; i++) {
		unsigned int tmp = copy[i + 1] - copy[i];
		if (tmp < min)
			min = tmp;
	}
	return min;
}

unsigned int Span::longestSpan() const {
	if (_numbers.size() < 2)
		throw Span::NotEnoughElementsException();
	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());
	return tmp[0] - tmp[tmp.size() - 1];
}