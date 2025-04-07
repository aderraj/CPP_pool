#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	private:
		const std::string	name;
		bool							_signed;
		const short				signGrade;
		const short				execGrade;

	public:
		AForm();
		AForm(std::string _name, short _signGrade, short _execGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		~AForm();
		const std::string&	getName() const;
		const bool&					getSign() const;
		const short&				getSignGrade() const;
		const short&				getExecGrade() const;
		void								beSigned(Bureaucrat& owner);
		virtual void				execute(const Bureaucrat& executor) = 0;

};

std::ostream&	operator<<(std::ostream& out, AForm& form);

#endif