/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeselee <yeselee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 23:23:58 by yeselee           #+#    #+#             */
/*   Updated: 2023/04/19 11:15:45 by yeselee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
	if (argc != 4) {
		std::cout << "Wrong argument" << std::endl;
		return 1;
	}

	std::ifstream readFile;
	std::ofstream writeFile;
	std::string str;
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string newFile;

	readFile.open(argv[1]);
	if (!readFile.is_open()) {
		std::cout << "File open error" << std::endl;
		return 1;
	}

	newFile = argv[1];
	newFile += ".replace";

	writeFile.open(newFile);
	if (!writeFile.is_open()) {
		std::cout << "File open error" << std::endl;
		readFile.close();
		return 1;
	}

	if (s1.length() == 0) {
		std::cout << "Wrong argument" << std::endl;
		readFile.close();
		writeFile.close();
		return 1;
	}

	while(!readFile.eof()) {
		std::getline(readFile, str);
		size_t index = 0;
		while (1) {
			index = str.find(argv[2], index);
			if (index != std::string::npos) {
				str.erase(index, s1.length());
				str.insert(index, s2);
				index += s2.length();
			}
			else
				break;
		}
		writeFile << str;
		if (!readFile.eof())
			writeFile << std::endl;
	}

	readFile.close();
	writeFile.close();
	return 0;
}