#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Form {

	public:
		Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		const std::string&	getName() const;
		const bool&					getSign() const;
		const short&				getSignGrade() const;
		const short&				getExecGrade() const;

	private:
		const std::string	name;
		bool							sign;
		const short				signGrade;
		const short				execGrade;
};

#endif