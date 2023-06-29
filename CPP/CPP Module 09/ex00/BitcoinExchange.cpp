#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref) {
	this->data = ref.data;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ref) {
	if (this != &ref) {
		this->data = ref.data;
	}
	return *this;
}

int BitcoinExchange::checkValidDate(std::string date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return 1;

	int year, month, day;

	std::string tmp;
	tmp = date.substr(0, 4);
	year = atoi(tmp.c_str());
	tmp = date.substr(5, 7);
	month = atoi(tmp.c_str());
	tmp = date.substr(8, 10);
	day = atoi(tmp.c_str());

	if (year < 1000 || year > 9999)
		return 1;
	if (month < 1 || month > 12)
		return 1;
	if (day < 1 || day > 31)
		return 1;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
		return 1;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		if (month == 2 && day > 29)
			return 1;
	}
	else if (month == 2 && day > 28)
		return 1;
	return 0;
}

int BitcoinExchange::checkValidPrice(std::string s) {
	if (s.length() == 0)
		return 1;

	char *end = NULL;
	double price = std::strtod(s.c_str(), &end);

	if (price == 0 && s == end)
		return 1;
	if (price < 0)
		return 1;
	return 0;
}

int BitcoinExchange::checkValidValue(std::string s) {
	if (s.length() == 0 || s.length() > 100) {
		std::cout << "Error: bad value" << std::endl;
		return 1;
	}

	char *end = NULL;
	double value = std::strtod(s.c_str(), &end);

	if (value == 0 && s == end)
		return 1;
	else if (value < 0) {
		std::cout << "Error: not a positive number" << std::endl;
		return 1;
	}
	else if (value > 1000) {
		std::cout << "Error: too large number" << std::endl;
		return 1;
	}
	else if (s.find('.') == 0) {
		std::cout << "Error: bad value" << std::endl;
		return 1;
	}
	else if (s.find('.') != s.rfind('.')) {
		std::cout << "Error: bad value" << std::endl;
		return 1;
	}
	for (size_t i = 0; i < s.length(); i++) {
		if ((s[i] < '0' || s[i] > '9') && s[i] != '.') {
			std::cout << "Error: bad value" << std::endl;
			return 1;
		}
	}


	return 0;
}

void BitcoinExchange::getDataFromCSV() {
	std::ifstream file("./data.csv");
	std::string buf;
	int date_idx;
	std::string date;
	double price;

	if (!file)
		throw std::runtime_error("cannot open data file");

	while (std::getline(file, buf)) {
		if (buf == "date,exchange_rate")
			continue;

		date_idx = buf.find(',');

		if (checkValidDate(buf.substr(0, date_idx))) {
			file.close();
			throw std::runtime_error("not a valid date");
		}

		if (checkValidPrice(buf.substr(date_idx + 1))) {
			file.close();
			throw std::runtime_error("not a valid price");
		}

		date = buf.substr(0, date_idx);
		std::istringstream iss(buf.substr(date_idx + 1)); 
		iss >> price;

		data[date] = price;
	}

	file.close();
}

void BitcoinExchange::exchange(std::string s) {
	std::ifstream file(s);
	std::string buf;
	std::string date;
	double value;
	int count = 0;
	int date_idx;
	std::map<std::string, double>::iterator iter;

	if (!file)
		throw std::runtime_error("cannot open input file");

	while (std::getline(file, buf)) {
		if (count == 0) {
			if (buf != "date | value") {
				file.close();
				throw std::runtime_error("not a valid format");
			}
			count++;
			continue;
		}

		date_idx = buf.find('|');
		if (buf[date_idx - 1] != ' ' || buf[date_idx + 1] != ' ') {
			std::cout << "Error: not a valid format" << std::endl;
			continue;
		}
		
		if (checkValidDate(buf.substr(0, date_idx - 1))) {
			std::cout << "Error: not a valid date" << std::endl;
			continue;						
		}

		if (checkValidValue(buf.substr(date_idx + 2))) {
			continue;
		}

		date = buf.substr(0, date_idx - 1);
		std::istringstream iss(buf.substr(date_idx + 2)); 
		iss >> value;

		iter = data.find(date);
		if (iter == data.end()) {
			iter = data.lower_bound(date);
			if (iter == data.begin()) {
				std::cout << "Error : not have value" << std::endl;
				continue;
			}
			iter--;
		}

		std::cout << date << " => " << value << " = " << std::setprecision(10) << iter->second * value << std::endl;		
	}
	
}