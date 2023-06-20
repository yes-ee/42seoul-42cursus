#include "AForm.hpp"

AForm::AForm() : name("empty"), sign_grade(150), execute_grade(150){
    this->status = false;
}

AForm::AForm(std::string name, int sign, int execute) : name(name), sign_grade(sign), execute_grade(execute){
	if (sign_grade < 1)
		throw AForm::GradeTooHighException();
	else if (sign_grade > 150)
		throw AForm::GradeTooLowException();
	if (execute_grade < 1)
		throw AForm::GradeTooHighException();
	else if (execute_grade > 150)
		throw AForm::GradeTooLowException();
    this->status = false;
}

AForm::~AForm() {
}

AForm::AForm(const AForm& ref) : name(ref.name), sign_grade(ref.sign_grade), execute_grade(ref.execute_grade) {
    this->status = ref.status;
}

AForm& AForm::operator=(const AForm& ref){
    if (this != &ref)
        this->status = ref.status;
    return *this;
}

std::string AForm::getName() const {
    return this->name;
}

bool AForm::getStatus() const {
    return this->status;
}

int AForm::getSignGrade() const {
    return this->sign_grade;
}

int AForm::getExecuteGrade() const {
    return this->execute_grade;
}

void AForm::beSigned(Bureaucrat bc) {
    if (this->sign_grade >= bc.getGrade())
        this->status = true;
    else
        throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Form Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Form Grade too low";
}

std::ostream& operator<<(std::ostream& out, const AForm& ref) {
	out << ref.getName() << ", sign " << std::boolalpha << ref.getStatus() << ", Form sign grade " << ref.getSignGrade() << ", Form execute grade " << ref.getExecuteGrade() << ".";
	return out;
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form is not signed";
}