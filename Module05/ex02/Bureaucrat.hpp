#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>
#include "Colors.hpp"
#include "AForm.hpp"

class AForm;

class Bureaucrat {

	private:
		const std::string	name;
		short							grade;

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
		void								signForm(AForm& form);
		void								executeForm(AForm const & form);

};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& ref);

#endif