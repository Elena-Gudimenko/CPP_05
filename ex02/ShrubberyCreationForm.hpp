#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string	_target;

protected:
	virtual void	executeAction() const;

public:
	// Orthodox Canonical Form
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	virtual ~ShrubberyCreationForm();

	// Parameterized constructor
	ShrubberyCreationForm(const std::string &target);

	// Getter
	const std::string	&getTarget() const;
};

#endif