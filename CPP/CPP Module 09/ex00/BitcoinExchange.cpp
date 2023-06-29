#include <BitcoinExchange.hpp>

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

	int cur = 0;
	int count = 0;
	int pos, year, month, day;

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
}

int BitcoinExchange::checkValidValue(std::string s) {
	if (s.length() == 0)
		return 1;

	char *end = NULL;
	double value = std::strtod(s.c_str(), &end);

	if (value == 0 && s == end)
		return 1;
	if (value < 0)
		return 1;
	if (end != s && end[0] != '\0' && (end[0] != 'f' || (end[0] == 'f' && end[1] != '\0')))
		return 1;
	return 0;
}

void BitcoinExchange::getDataFromCSV() {
	std::ifstream file("./data.csv");
	std::string buf;
	int pos;
	int date_idx;
	std::string date;
	std::string value;

	if (!file)
		throw std::runtime_error("cannot open data file");

	while (std::getline(file, buf)) {
		if (buf == "data,exchange_rate")
			continue;

		date_idx = buf.find(',');

		if (checkValidDate(buf.substr(0, date_idx)))
			throw std::runtime_error("not a valid date");

		if (checkValidValue(buf.substr(date_idx + 1)))
			throw std::runtime_error("not a valid value");

		date = buf.substr(0, date_idx);
		std::istringstream iss(buf.substr(date_idx)); 
		iss >> value;
	}

	file.close();
}

void BitcoinExchange::exchange() {

}