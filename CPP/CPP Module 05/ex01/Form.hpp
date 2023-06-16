#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# include <exception>

class Form {
    private:
        const std::string name;
        bool status;
        const int sign_grade;
        const int execute_grade;
    public:
        Form();
        Form(std::string name, int sign, int execute);
        ~Form();
        Form(const Form& ref);
        Form& operator=(const Form& ref);
        std::string getName() const;
        bool getStatus() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        void beSigned(Bureaucrat bc);
		class GradeTooHighException:public std::exception{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException:public std::exception{
			public:
				const char* what() const throw();
 		};

};

std::ostream& operator<<(std::ostream& out, const Form& ref);

#endif
