#include "RobotomyRequestForm.hpp"
#include <cstdlib>   // std::rand, std::srand
#include <ctime>     // std::time

// Default constructor
RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("default") {}

// Parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {}

// Copy assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}
// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// Getter
const std::string& RobotomyRequestForm::getTarget() const {
    return this->_target;
}

// The specific action of this form
void RobotomyRequestForm::executeAction() const {
    static bool seeded = false;

    if (!seeded) {
        std::srand(std::time(NULL));
        seeded = true;
    }
    std::cout << "* BZZZZZZ... DRRRRRR... BZZZ *" << std::endl;
    if (std::rand() % 2 == 0) {
        std::cout << this->_target << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "The robotomy on " << this->_target << " failed." << std::endl;
    }
}