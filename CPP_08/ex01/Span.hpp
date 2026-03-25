#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>

class Span{

	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;
		Span();

	public:
		Span(unsigned int nbr);
		Span(const Span &copy);
		Span &operator=(const Span &src);
		~Span();

		void addNumber(int nbr);
		template <typename Input>
		void addNumber(Input first, Input last)
		{
			for (; first != last; ++first) {
				if (_numbers.size() >= _maxSize)
					throw SpanFullException();
				_numbers.push_back(*first);
			}
		}
		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		class SpanFullException : public std::exception {
			public:
				virtual const char* what() const throw(){
					return "ERROR: Span is full";
				}
		};
		class NotEnoughElementsException : public std::exception {
			public:
				virtual const char* what() const throw(){
					return "ERROR: Not enough elements";
				}
		};
};

#endif