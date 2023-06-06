#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
}

Bureaucrat::Bureaucrat(std::string name, int grade) {
	this->name = name;
	this->grade = grade;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) {
	if (this != &ref) {
		this->name = ref.name;
		this->grade = ref.grade;
	}
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref) {
	
}