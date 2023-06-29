#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
		MutantStack() {};
		~MutantStack() {};
		MutantStack(const MutantStack& ref) { 
            *this = ref;
        };
		MutantStack& operator=(const MutantStack& ref) {
            if (this != &ref) {
                *this = ref;
            }
            return *this;
        };

        typedef typename MutantStack<T>::stack::container_type::iterator iterator;
        iterator begin() {
            return this->c.begin();
        }
        iterator end() {
            return this->c.end();
        }

        typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
        reverse_iterator rbegin() {
            return this->c.rbegin();
        }
        reverse_iterator rend() { 
            return this->c.rend();
        }
};

#endif