#ifndef AForm_HPP
# define AForm_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>
# include <exception>

class AForm {
    private:
        const std::string name;
        bool status;
        const int sign_grade;
        const int execute_grade;
    public:
        AForm();
        AForm(std::string name, int sign, int execute);
        virtual ~AForm();
        AForm(const AForm& ref);
        AForm& operator=(const AForm& ref);
        std::string getName() const;
        bool getStatus() const;
        int getSignGrade() const;
        int getExecuteGrade() const;
        virtual std::string getTarget() const = 0;
        void beSigned(Bureaucrat bc);
		class GradeTooHighException:public std::exception{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException:public std::exception{
			public:
				const char* what() const throw();
 		};
        class FormNotSignedException:public std::exception {
            public:
                const char* what() const throw();
        };
        virtual void execute(Bureaucrat const& executer) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& ref);

#endif
