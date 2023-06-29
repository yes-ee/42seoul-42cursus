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
		int checkValidValue(std::string s);

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& ref);
		BitcoinExchange& operator=(const BitcoinExchange& ref);

		void getDataFromCSV();	//csv 파일에서 데이터 읽어서 map에 저장
		void exchange();	//input.txt 읽으면서 값 출력
};

#endif