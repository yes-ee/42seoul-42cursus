#include "AForm.hpp"

AForm::AForm() : name("empty"), signGrade(150), executeGrade(150){
    this->status = false;
}

AForm::AForm(std::string name, int sign, int execute) : name(name), signGrade(sign), executeGrade(execute){
	if (signGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150)
		throw AForm::GradeTooLowException();
	if (executeGrade < 1)
		throw AForm::GradeTooHighException();
	else if (executeGrade > 150)
		throw AForm::GradeTooLowException();
    this->status = false;
}

AForm::~AForm() {
}

AForm::AForm(const AForm& ref) : name(ref.name), signGrade(ref.signGrade), executeGrade(ref.executeGrade) {
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
    return this->signGrade;
}

int AForm::getExecuteGrade() const {
    return this->executeGrade;
}

void AForm::beSigned(Bureaucrat bc) {
    if (this->signGrade >= bc.getGrade())
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
