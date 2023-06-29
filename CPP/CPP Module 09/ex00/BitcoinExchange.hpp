#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <stdexcept>
# include <iostream>
# include <fstream>
# include <sstream>

class BitcoinExchange {
	private:
		std::map<std::string, double> data;
		int checkValidDate(std::string date);
		int checkValidPrice(std::string s);
		int checkValidValue(std::string s);
		int checkInputFile(std::string s);

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& ref);
		BitcoinExchange& operator=(const BitcoinExchange& ref);

		void getDataFromCSV();
		void exchange(std::string s);
};

#endif