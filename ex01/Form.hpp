#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;   // forward declaration instead  #include

class Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

public:
	// Constructors & Destructor
	Form();
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	// Parameterized constructor
	Form(const std::string &name, int gradeToSign, int gradeToExecute);

	// Getters
	const std::string	&getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	// Signing
	void	beSigned(const Bureaucrat &b);

	// Exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif