#include "Form.hpp"
#include "Bureaucrat.hpp"  

// Default constructor
Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

// Parameterized constructor
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw Form::GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw Form::GradeTooLowException();
    }
}

// Copy constructor
Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

// Copy assignment operator
Form& Form::operator=(const Form& other) {
    if (this != &other) {
        // _name, _gradeToSign and _gradeToExecute are const.
        // Only _isSigned can be copied.
        this->_isSigned = other._isSigned;
    }
    return *this;
}

// Destructor
Form::~Form() {}


// Getters
const std::string& Form::getName() const {
    return this->_name;
}

bool Form::getIsSigned() const {
    return this->_isSigned;
}

int Form::getGradeToSign() const {
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const {
    return this->_gradeToExecute;
}

// Signing
void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->_gradeToSign) {
        throw Form::GradeTooLowException();
    }
    this->_isSigned = true;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low";
}


// Stream insertion overload
std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form " << f.getName()
       << ", signed: " << (f.getIsSigned() ? "yes" : "no")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute() << ".";
    return os;
}