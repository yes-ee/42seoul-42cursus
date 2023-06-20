#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default"){
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137){
    this->target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) : AForm("ShrubberyCreationForm", 145, 137) {
    this->target = ref.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref) {
    if (this != &ref) {
        this->target = ref.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executer) const{
    if (executer.getGrade() > this->getExecuteGrade()) {
        throw Bureaucrat::GradeTooLowException();
    }
    else if (this->getStatus() == false) {
        throw FormNotSignedException();
    }
    else {
        std::ofstream file(this->target + "_shrubbery");
        if (file.fail()) {
            std::cout << "file open failed" << std::endl;
            return;
        }
        else {
            std::string tree = \
"                           %                         %            \n\
 @@@     %    @@     @@@@                                  *       \n\
    @@ %     @  %   @   %          %               ;      ***      \n\
     @@    @      @                               #     *****     \n\
 @@@   @@@@@  @@@@@@___    %         %           {###}  *******\n\
    @-@  @   @      @@@@       %               <## ####>********\n\
  @@@@@   @ @         @@@@@               %      {###}***********\n\
    %  @  @@ /@@@@@                          <###########> *******\n\
        @-@@@@    V     %          %           {#######}******* ***\n\
  %       @@      v        { }             <###############>*******\n\
          @@               {^^,               {## ######}***** ****\n\
  %      @@     %          (   `-;       <###################> ****\n\
         @@           _     `;;~~           {#############}********\n\
         @@   %      /(______);        <################  #####>***\n\
   %     @@@        (         (           {##################}*****\n\
          @@@        |:------( )     <##########################>**\n\
 @@@@     @@@      _//        \\        {###   ##############}*****\n\
@@@@@@@  @@@@@    / /@@@@@@@@@ vv  <##############################>\n\
@@@@@@@ @@@@@@@ @@@@@@@@@@@@@@@@@@@       @@@@@@  @@@@@@@  @@@@\n\
@@@@@@###@@@@@### @@@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n\
@@@@@@@@###@##@@ @@@@@@@@@@@@@@@@@@@@@ @@@@@   @@@@@@@@@@@@@@@@@@@\n\
@@@@@@@@@@@### @@@@@@@@@@@@@@@@@@@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@\n\
-@@@@@@@@@#####@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";

            file << tree;
            file.close();
        }
    }
}

std::string ShrubberyCreationForm::getTarget() const{
    return this->target;
}

