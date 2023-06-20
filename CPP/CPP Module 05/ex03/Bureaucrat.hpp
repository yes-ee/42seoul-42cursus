#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class AForm;

class Bureaucrat {
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& ref);
		Bureaucrat& operator=(const Bureaucrat& ref);
		std::string getName() const;
		int getGrade() const;
		void increaseGrade();
		void decreaseGrade();
		void signForm(AForm &ref);
		class GradeTooHighException:public std::exception{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException:public std::exception{
			public:
				const char* what() const throw();
 		};
		void executeForm(AForm const& form);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& ref);

#endif
