#include "Bureaucrat.hpp"
#include "Form.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
    if (grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    } else if (grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

// Copy assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        // _name is const, so we cannot assign to it.
        // We only assign the non-const members.
        this->_grade = other._grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}


// Getters
const std::string& Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

// Increment grade (1 is max, so increment means decreasing the number)
void Bureaucrat::incrementGrade() {
    if (this->_grade <= 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    this->_grade--;
}

// Decrement grade (150 is min, so decrement means increasing the number)
void Bureaucrat::decrementGrade() {
    if (this->_grade >= 150) {
        throw Bureaucrat::GradeTooLowException();
    }
    this->_grade++;
}

// Form signing
void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->_name << " couldn't sign " << form.getName()
                  << " because " << e.what() << "." << std::endl;
    }
}

// Exception what() override
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat grade is too high! (Highest is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat grade is too low! (Lowest is 150)";
}

// Stream insertion overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}