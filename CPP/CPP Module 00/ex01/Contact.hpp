#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string secret;

	public:
		void set_first_name(std::string first_name);
		void set_last_name(std::string last_name);
		void set_nickname(std::string nickname);
		void set_phone_number(std::string phone_number);
		void set_secret(std::string secret);

		std::string get_first_name();
		std::string get_last_name();
		std::string get_nickname();
};

#endif