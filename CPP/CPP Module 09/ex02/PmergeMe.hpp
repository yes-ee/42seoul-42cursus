#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <map>
# include <string>
# include <stdexcept>
# include <iostream>
# include <vector>
# include <deque>
# include <time.h>
# include <utility>

class PmergeMe {
	private:
		std::vector<int> v;
	    std::vector<int> res;
	    std::deque<int> resd;
		std::deque<int> d;
		clock_t vtime;
		clock_t dtime;
		static bool cmp(std::pair<int, int> a, std::pair<int, int> b);

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& ref);
		PmergeMe& operator=(const PmergeMe& ref);

		void checkInput(int count, char *argv[]);
		void print();
		void sortVector();
		void sortDeque();
		void printTime();
};

#endif