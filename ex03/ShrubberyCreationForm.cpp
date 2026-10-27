#include <fstream>   // std::ofstream
#include "ShrubberyCreationForm.hpp"


// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

// Parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

// Copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Getter
const std::string& ShrubberyCreationForm::getTarget() const {
    return this->_target;
}

// The specific action of this form
void ShrubberyCreationForm::executeAction() const {
    std::string     filename = this->_target + "_shrubbery";
    std::ofstream   file(filename.c_str());

    if (!file.is_open()) {
        std::cerr << "Error: could not create file " << filename << std::endl;
        return;
    }

    file << "        *" << std::endl;
    file << "       /|\\" << std::endl;
    file << "      /*|O\\" << std::endl;
    file << "     /*/|\\*\\" << std::endl;
    file << "    /X/O|*\\X\\" << std::endl;
    file << "   /*/X/|\\X\\*\\" << std::endl;
    file << "  /O/*/X|*\\O\\X\\" << std::endl;
    file << "       |X|" << std::endl;
    file << "       |X|" << std::endl;
    file << std::endl;

    file.close();
}