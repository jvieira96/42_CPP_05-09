#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <string>



class BitcoinExchange {

    private:
		std::map<std::string, float> _data;
		bool isValidDate(const std::string& date) const;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();

		bool loadData(const std::string& filename);
		void processInput(const std::string& filename);

};


#endif