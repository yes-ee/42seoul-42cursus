#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>

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
		std::string getName();
		int getGrade();
		class GradeTooHighException : public std::exception{
			// void report();
		};
		class GradeTooLowException : public std::exception{
			// void report();
 		};
}

#endif