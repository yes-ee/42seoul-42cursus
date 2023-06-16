#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("empty"){
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref) : name(ref.name) {
	this->grade = ref.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref) {
	if (this != &ref)
		this->grade = ref.grade;
	return *this;
}

std::string Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::increaseGrade() {
	if (grade - 1 < 1)
		throw GradeTooHighException();
	this->grade--;
	std::cout << "Grade is " << this->grade << std::endl;
}

void Bureaucrat::decreaseGrade() {
	if (grade + 1 > 150)
		throw GradeTooLowException();
	this->grade++;
	std::cout << "Grade is " << this->grade << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Bureaucrat : Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat : Grade too low";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& ref) {
	out << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".";
	return out;
}

void Bureaucrat::signForm(Form& ref) {
	try {
		ref.beSigned(*this);
		std::cout << this->name << " signed " << ref.getName() << std::endl;
	}
	catch (std::exception& e){
		std::cout << this->name << " couldn't sign " << ref.getName() << " because " << e.what() << std::endl;
	}
}