#include "Intern.hpp"

Intern::Intern() {
}

Intern::~Intern() {
}

Intern::Intern(const Intern& ref) {
    (void)ref;
}

Intern& Intern::operator=(const Intern& ref) {
    if (this != &ref) {
        //if info added, do something
    }
    return *this;
}

AForm* Intern::makeForm(std::string name, std::string target) {
    AForm* form = NULL;
    int index = 3;
    std::string names[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    for (int i = 0; i < 3; i++) {
        if (name == names[i]) {
            index = i;
            break;
        }
    }
    try {
        switch(index)
        {
        case 0:
            form = new ShrubberyCreationForm(target);
            break;
        case 1:
            form = new RobotomyRequestForm(target);
            break;
        case 2:
            form = new PresidentialPardonForm(target);
            break;
        default:
            throw NameNotExistException();
        }
        std::cout << "Intern creates " << name << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return form;
}

const char* Intern::NameNotExistException::what() const throw() {
	return "Name doesn't exist";
}
