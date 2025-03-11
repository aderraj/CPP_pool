#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>
#include "Colors.hpp"

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
		const std::string&	getName();
		short				getGrade();

	private:
		const std::string	name;
		short							grade;

};
#endif