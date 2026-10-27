#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat sheff("Sheff", 1);
        Bureaucrat middle("Middle", 70);
        Bureaucrat junior("Junior", 150);

        std::cout << " >>>>> ShrubberyCreationForm (145 / 137) <<<<<" << std::endl;
        ShrubberyCreationForm shrub("home");
        std::cout << shrub << std::endl;
        sheff.executeForm(shrub);     // not signed -> error
        junior.signForm(shrub);       // 150 > 145 -> can't sign
        middle.signForm(shrub);       // 70 <= 145 -> signed
        junior.executeForm(shrub);    // 150 > 137 -> grade too low
        middle.executeForm(shrub);    // OK -> file home_shrubbery created

        std::cout << "\n >>>>> RobotomyRequestForm (72 / 45) <<<<<" << std::endl;
        RobotomyRequestForm robot("Bender");
        middle.signForm(robot);       // 70 <= 72 -> signed
        middle.executeForm(robot);    // 70 > 45 -> grade too low
        for (int i = 0; i < 4; i++)
            sheff.executeForm(robot); // ~50% success

        std::cout << "\n >>>>> PresidentialPardonForm (25 / 5) <<<<<" << std::endl;
        PresidentialPardonForm pardon("Arthur Dent");
        middle.signForm(pardon);      // 70 > 25 -> can't sign
        sheff.signForm(pardon);       // OK
        middle.executeForm(pardon);   // 70 > 5 -> grade too low
        sheff.executeForm(pardon);    // OK

        std::cout << "\n >>>>> Polymorphism: AForm pointer <<<<<" << std::endl;
        AForm* form = new PresidentialPardonForm("Ford Prefect");
        std::cout << *form << std::endl;
        sheff.signForm(*form);
        sheff.executeForm(*form);
        delete form;                  // virtual destructor -> no leak
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}