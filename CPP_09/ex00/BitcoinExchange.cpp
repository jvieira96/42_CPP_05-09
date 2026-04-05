#include "BitcoinExchange.hpp"
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		_data = other._data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.length(); i++) {
		if (i == 4 || i == 7) 
			continue;
		if (date[i] < '0' || date[i] > '9') 
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30) return false;
	} else if (month == 2) {
		bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (day > (isLeap ? 29 : 28)) 
			return false;
	}
	return true;
}

bool BitcoinExchange::loadData(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file " << filename << std::endl;
		return false;
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		size_t delim = line.find(',');
		if (delim != std::string::npos) {
			std::string date = line.substr(0, delim);
			float value = std::atof(line.substr(delim + 1).c_str());
			_data[date] = value;
		}
	}
	file.close();
	return true;
}

void BitcoinExchange::processInput(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		size_t delim = line.find(" | ");
		if (delim == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, delim);
		std::string valStr = line.substr(delim + 3);

		if (!isValidDate(date)) {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		if (valStr.empty() || valStr.find_first_not_of("0123456789.-+") != std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		float value = std::atof(valStr.c_str());

		if (value < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<std::string, float>::iterator it = _data.lower_bound(date);
		
		if (it == _data.end() || it->first != date) {
			if (it == _data.begin()) {
				std::cout << "Error: no earlier date found in database => " << date << std::endl;
				continue;
			}
			--it;
		}
		std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
	}
	file.close();
}