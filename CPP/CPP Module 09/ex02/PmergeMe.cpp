#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::~PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe& ref) {
    this->v = ref.v;
    this->d = ref.d;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& ref) {
    if (this != &ref) {
        this->v = ref.v;
        this->d = ref.d;
    }
    return *this;
}

void PmergeMe::checkInput(int count, char *argv[]) {
    for (int i = 1; i < count; i++) {
        for (int j = 0; j < argv[i][j]; j++) {
            if (j == 0 && argv[i][j] == '+') {
                if (argv[i][j + 1])
                    continue;
                throw std::runtime_error("Error: wrong number");
            }
            else if ((argv[i][j] < '0' || argv[i][j] > '9')) {
                throw std::runtime_error("Error: wrong number");
            }
        }
        int num = atoi(argv[i]);
        v.push_back(num);
        d.push_back(num);
    }
}

void PmergeMe::print() {
    std::cout << "Before: ";
    for (unsigned long i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    sortVector();
    sortDeque();

    std::cout << "After: ";
    for (unsigned long i = 0; i < res.size(); i++)
        std::cout << res[i] << " ";
    std::cout << std::endl;
}

bool PmergeMe::cmp(std::pair<int ,int> a, std::pair<int, int> b) {
    return a.first < b.first;
}

void PmergeMe::sortVector() {
    clock_t start, finish;
    unsigned int jacobsthal[20] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
    
    start = clock();

    if (v.size() == 1) {
        res.push_back(v[0]);
        finish = clock();
        vtime = finish - start;
        return;
    }

    int last = -1;
    int flag = 0;
    std::vector<std::pair<int, int> > arr;

    if (v.size() % 2)
        last = v[v.size() - 1];

    for (unsigned int i = 0; i < v.size() - 1; i += 2) {
        if (v[i] > v[i + 1])
            arr.push_back(std::make_pair(v[i], v[i + 1]));
        else
            arr.push_back(std::make_pair(v[i + 1], v[i]));
    }

    sort(arr.begin(), arr.end(), cmp);

    for (unsigned int i = 0; i < arr.size(); i++) {
        res.push_back(arr[i].first);
    }

    unsigned int jidx = 1;
    while (!flag) {
        for (unsigned int i = jacobsthal[jidx]; i > jacobsthal[jidx - 1]; i--) {
            if (i >= arr.size()) {
                i = arr.size();
                flag = 1;
            }

            int end_num = arr[i - 1].first;
            int target = arr[i - 1].second;

            res.insert(std::lower_bound(res.begin(), std::find(res.begin(), res.end(), end_num), target), target);
        }
        jidx++;
    }

    if (last >= 0)
        res.insert(std::lower_bound(res.begin(), res.end(), last), last);

    finish = clock();
    vtime = finish - start;
}


void PmergeMe::sortDeque() {
    clock_t start, finish;
    unsigned int jacobsthal[20] = {0, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};


    start = clock();

    if (d.size() == 1) {
        resd.push_back(d[0]);
        finish = clock();
        dtime = finish - start;
        return;
    }

    int last = -1;
    int flag = 0;
    std::deque<std::pair<int, int> > arr;

    if (d.size() % 2)
        last = d[d.size() - 1];

    for (unsigned int i = 0; i < d.size() - 1; i += 2) {
        if (d[i] > d[i + 1])
            arr.push_back(std::make_pair(d[i], d[i + 1]));
        else
            arr.push_back(std::make_pair(d[i + 1], d[i]));
    }

    sort(arr.begin(), arr.end(), cmp);

    for (unsigned int i = 0; i < arr.size(); i++)
        resd.push_back(arr[i].first);

    unsigned int jidx = 1;
    while (!flag) {
        for (unsigned int i = jacobsthal[jidx]; i > jacobsthal[jidx - 1]; i--) {
            if (i >= arr.size()) {
                i = arr.size();
                flag = 1;
            }

            int end_num = arr[i - 1].first;
            int target = arr[i - 1].second;

            resd.insert(std::lower_bound(resd.begin(), std::find(resd.begin(), resd.end(), end_num), target), target);
        }
        jidx++;
    }
    if (last >= 0)
        resd.insert(std::lower_bound(resd.begin(), resd.end(), last), last);

    finish = clock();
    dtime = finish - start;
}

void PmergeMe::printTime() {
    std::cout << "Time to sort with std::vector : " << vtime << "ms" << std::endl;
    std::cout << "Time to sort with std::deque : " << dtime << "ms" << std::endl;
}