#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default"){
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45){
    this->target = target;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref) : AForm("RobotomyRequestForm", 72, 45) {
    this->target = ref.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref) {
    if (this != &ref) {
        this->target = ref.target;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executer) const{
    if (executer.getGrade() > this->getExecuteGrade()) {
        throw Bureaucrat::GradeTooLowException();
    }
    else if (this->getStatus() == false) {
        throw FormNotSignedException();
    }
    else {
        std::cout << "drill : drrrrrr..." << std::endl;
        std::srand(std::time(NULL));
        if (rand() % 2)
            std::cout << "Robotomy success!" << std::endl;
        else
            std::cout << "Robotomy failed..." << std::endl;
    }
}

std::string RobotomyRequestForm::getTarget() const{
    return this->target;
}

