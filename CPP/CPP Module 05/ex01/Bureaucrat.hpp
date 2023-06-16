#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Form;

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
		void signForm(Form &ref);
		class GradeTooHighException:public std::exception{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException:public std::exception{
			public:
				const char* what() const throw();
 		};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& ref);

#endif
