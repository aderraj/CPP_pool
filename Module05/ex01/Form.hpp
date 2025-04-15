#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

# define RED "\x1b[91m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[93m"
# define CYAN "\x1b[36m"
# define RESET "\x1b[0m"
# define BOLD "\x1b[1m"

class Bureaucrat;

class AForm {

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

	private:
		const std::string	name;
		bool							_signed;
		const short				signGrade;
		const short				execGrade;
};

std::ostream&	operator<<(std::ostream& out, AForm& form);

#endif