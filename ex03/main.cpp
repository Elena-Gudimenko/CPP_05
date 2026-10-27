#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    try {
        Intern      someRandomIntern;
        Bureaucrat  sheff("Sheff", 1);
        AForm*      form;

        std::cout << " >>>>> Robotomy request <<<<<" << std::endl;
        form = someRandomIntern.makeForm("robotomy request", "Bender");
        if (form) {
            std::cout << *form << std::endl;
            sheff.signForm(*form);
            sheff.executeForm(*form);
            delete form;
        }

        std::cout << "\n >>>>> Presidential pardon <<<<<" << std::endl;
        form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        if (form) {
            sheff.signForm(*form);
            sheff.executeForm(*form);
            delete form;
        }

        std::cout << "\n >>>>> Shrubbery creation <<<<<" << std::endl;
        form = someRandomIntern.makeForm("shrubbery creation", "garden");
        if (form) {
            sheff.signForm(*form);
            sheff.executeForm(*form);   // creates garden_shrubbery
            delete form;
        }

        std::cout << "\n >>>>> Unknown form <<<<<" << std::endl;
        form = someRandomIntern.makeForm("coffee request", "Sheff");
        if (form == NULL)
            std::cout << "makeForm returned NULL" << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}