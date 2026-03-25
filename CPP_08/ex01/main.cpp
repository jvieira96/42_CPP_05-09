#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main() {
	// sybject tests
	std::cout << "=== Basic Test ===" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest: " << sp.longestSpan() << std::endl;

	// Test SpanFullException
	std::cout << "\n=== SpanFullException Test ===" << std::endl;
	Span spFull = Span(3);
	try {
		spFull.addNumber(1);
		spFull.addNumber(2);
		spFull.addNumber(3);
		spFull.addNumber(4);
		std::cout << "Should have thrown SpanFullException" << std::endl;
	} catch (const std::exception &e) {
		std::cout << "ERROR: " << e.what() << std::endl;
	}

	// Test NotEnoughElementsException on empty Span
	std::cout << "\n=== NotEnoughElementsException (empty) Test ===" << std::endl;
	Span emptySpan = Span(5);
	try {
		emptySpan.shortestSpan();
		std::cout << "Should have thrown NotEnoughElementsException" << std::endl;
	} catch (const std::exception &e) {
		std::cout << "ERROR: " << e.what() << std::endl;
	}

	// Test NotEnoughElementsException on single element
	std::cout << "\n=== NotEnoughElementsException (single) Test ===" << std::endl;
	Span spSingle = Span(5);
	spSingle.addNumber(42);
	try {
		spSingle.longestSpan();
		std::cout << "ERROR: Should have thrown NotEnoughElementsException" << std::endl;
	} catch (const std::exception &e) {
		std::cout << "✓ Caught: " << e.what() << std::endl;
	}

	// Iterator range test with 10,000 elements
	std::cout << "\n=== Iterator Range Test (10,000 elements) ===" << std::endl;
	std::vector<int> v;
	for (int i = 0; i < 10000; i++) {
		v.push_back(rand() % 100000);
	}
	Span sp2 = Span(10000);
	sp2.addNumber(v.begin(), v.end());
	std::cout << "Shortest: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest: " << sp2.longestSpan() << std::endl;

	// Test SpanFullException with iterator range
	std::cout << "\n=== SpanFullException (iterator range) Test ===" << std::endl;
	Span spLimited = Span(5);
	std::vector<int> vLarge;
	for (int i = 0; i < 10; i++) {
		vLarge.push_back(i);
	}
	try {
		spLimited.addNumber(vLarge.begin(), vLarge.end());
		std::cout << "ERROR: Should have thrown SpanFullException" << std::endl;
	} catch (const std::exception &e) {
		std::cout << "✓ Caught: " << e.what() << std::endl;
	}

	return 0;
}