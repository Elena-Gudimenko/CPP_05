#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class AForm;

class Bureaucrat
{
private:
    const std::string   _name;
    int                 _grade;
    
public:
    // Constructors & Destructor
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // Getters
    const std::string&  getName() const;
    int                 getGrade() const;
    
    // Grade modifications
    void    incrementGrade();
    void    decrementGrade();

    // Form signing & executing
    void signForm(AForm& form);
    void executeForm(const AForm& form) const;

    // Exceptions
    class   GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif