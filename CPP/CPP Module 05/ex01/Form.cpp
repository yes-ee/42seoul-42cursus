#include "Form.hpp"

Form::Form() : name("empty"), signGrade(150), executeGrade(150){
    this->status = false;
}

Form::Form(std::string name, int sign, int execute) : name(name), signGrade(sign), executeGrade(execute){
	if (signGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150)
		throw Form::GradeTooLowException();
	if (executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (executeGrade > 150)
		throw Form::GradeTooLowException();
    this->status = false;
}

Form::~Form() {
}

Form::Form(const Form& ref) : name(ref.name), signGrade(ref.signGrade), executeGrade(ref.executeGrade) {
    this->status = ref.status;
}

Form& Form::operator=(const Form& ref){
    if (this != &ref)
        this->status = ref.status;
    return *this;
}

std::string Form::getName() const {
    return this->name;
}

bool Form::getStatus() const {
    return this->status;
}

int Form::getSignGrade() const {
    return this->signGrade;
}

int Form::getExecuteGrade() const {
    return this->executeGrade;
}

void Form::beSigned(Bureaucrat bc) {
    if (this->signGrade >= bc.getGrade())
        this->status = true;
    else
        throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form Grade too low";
}

std::ostream& operator<<(std::ostream& out, const Form& ref) {
	out << ref.getName() << ", sign " << std::boolalpha << ref.getStatus() << ", form sign grade " << ref.getSignGrade() << ", form execute grade " << ref.getExecuteGrade() << ".";
	return out;
}
