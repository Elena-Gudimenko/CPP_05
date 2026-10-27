#include "AForm.hpp"
#include "Bureaucrat.hpp"  

// Default constructor
AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

// Parameterized constructor
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw AForm::GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw AForm::GradeTooLowException();
    }
}

// Copy constructor
AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

// Copy assignment operator
AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        // _name, _gradeToSign and _gradeToExecute are const.
        // Only _isSigned can be copied.
        this->_isSigned = other._isSigned;
    }
    return *this;
}

// Destructor
AForm::~AForm() {}


// Getters
const std::string& AForm::getName() const {
    return this->_name;
}

bool AForm::getIsSigned() const {
    return this->_isSigned;
}

int AForm::getGradeToSign() const {
    return this->_gradeToSign;
}

int AForm::getGradeToExecute() const {
    return this->_gradeToExecute;
}

// Signing
void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->_gradeToSign) {
        throw AForm::GradeTooLowException();
    }
    this->_isSigned = true;
}

//Executing: common checks, then the specific action
void AForm::execute(const Bureaucrat& executor) const {
    if (!this->_isSigned) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->_gradeToExecute) {
        throw AForm::GradeTooLowException();
    }
    this->executeAction();
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw() {
    return "Form grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed";
}


// Stream insertion overload
std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form " << f.getName()
       << ", signed: " << (f.getIsSigned() ? "yes" : "no")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute() << ".";
    return os;
}