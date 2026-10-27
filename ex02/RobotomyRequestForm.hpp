#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
	    std::string	_target;

    protected:
	    virtual void	executeAction() const;
    public:
        	// Orthodox Canonical Form
	    RobotomyRequestForm();
	    RobotomyRequestForm(const RobotomyRequestForm &other);
	    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
	    virtual ~RobotomyRequestForm();

	    // Parameterized constructor
	    RobotomyRequestForm(const std::string &target);

	    // Getter
	    const std::string	&getTarget() const;

};

#endif