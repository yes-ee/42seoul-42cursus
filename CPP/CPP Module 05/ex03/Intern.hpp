#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
    public:
        Intern();
        ~Intern();
        Intern(const Intern& ref);
        Intern& operator=(const Intern& ref);
        AForm* makeForm(std::string name, std::string target);
        class NameNotExistException:public std::exception {
            public:
                const char* what() const throw();
        };
};

#endif
