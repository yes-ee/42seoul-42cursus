#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default"){
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5){
    this->target = target;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref) : AForm("PresidentialPardonForm", 25, 5) {
    this->target = ref.target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref) {
    if (this != &ref) {
        this->target = ref.target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const& executer) const{
    if (executer.getGrade() > this->getExecuteGrade()) {
        throw Bureaucrat::GradeTooLowException();
    }
    else if (this->getStatus() == false) {
        throw FormNotSignedException();
    }
    else {
        std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    }
}

std::string PresidentialPardonForm::getTarget() const{
    return this->target;
}
