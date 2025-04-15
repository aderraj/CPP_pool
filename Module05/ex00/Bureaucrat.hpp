#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

# define RED "\x1b[91m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[93m"
# define CYAN "\x1b[36m"
# define RESET "\x1b[0m"
# define BOLD "\x1b[1m"

class Bureaucrat {

	public:
		class GradeTooHighException : public std::exception {
			public:
				const char*	what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char*	what() const throw();
		};
		Bureaucrat();
		Bureaucrat(std::string name, short grade)
						throw(GradeTooHighException&, GradeTooLowException&) ;
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		const std::string&	getName() const;
		const short&				getGrade() const;
		void								incrementGrade();
		void								decrementGrade();

	private:
		const std::string	name;
		short							grade;

};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& ref);

#endif