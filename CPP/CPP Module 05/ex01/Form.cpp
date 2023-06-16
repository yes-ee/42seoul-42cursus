#include "Form.hpp"

Form::Form() : name("empty"), sign_grade(150), execute_grade(150){
    this->status = false;
}

Form::Form(std::string name, int sign, int execute) : name(name), sign_grade(sign), execute_grade(execute){
	if (sign_grade < 1)
		throw Form::GradeTooHighException();
	else if (sign_grade > 150)
		throw Form::GradeTooLowException();
	if (execute_grade < 1)
		throw Form::GradeTooHighException();
	else if (execute_grade > 150)
		throw Form::GradeTooLowException();
    this->status = false;
}

Form::~Form() {
}

Form::Form(const Form& ref) : name(ref.name), sign_grade(ref.sign_grade), execute_grade(ref.execute_grade) {
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
    return this->sign_grade;
}

int Form::getExecuteGrade() const {
    return this->execute_grade;
}

void Form::beSigned(Bureaucrat bc) {
    if (this->sign_grade >= bc.getGrade())
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
