#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    std::cout << "--- Creating valid and invalid Forms ---" << std::endl;
    try {
        Form tax("Tax Form", 50, 10);
        std::cout << tax << std::endl;

        // This will throw exception
        Form top("Top Secret Form", 0, 10); 
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    try {
        Form top("Top Secret Form", 50, 151); // grade to execute too low
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Signing Forms ---" << std::endl;
    try {
        Bureaucrat sheff("Sheff", 1);
        Bureaucrat junior("Junior", 150);
        
        Form doc("Important Document", 50, 50);
        std::cout << doc << std::endl;

        junior.signForm(doc); // Junior fails
        std::cout << doc << std::endl; // Still false

        sheff.signForm(doc); // Sheff succeeds
        std::cout << doc << std::endl; // True now

        sheff.signForm(doc); // Already signed logic (it will just set true again and print signed)
    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Signing: grade exactly equal ---" << std::endl;
    try {
        Bureaucrat mid("Mid", 50);
        Form tax1("TaxForm", 50, 25);
        mid.signForm(tax1);              // 50 == 50 -> signed
        std::cout << tax1 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
