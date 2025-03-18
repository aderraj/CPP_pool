#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	public:
		Form();
		Form(std::string _name, short _signGrade, short _execGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		const std::string&	getName() const;
		const bool&					getSign() const;
		const short&				getSignGrade() const;
		const short&				getExecGrade() const;
		void								beSigned(Bureaucrat& owner);

	private:
		const std::string	name;
		bool							_signed;
		const short				signGrade;
		const short				execGrade;
};

std::ostream&	operator<<(std::ostream& out, Form& form);

#endif