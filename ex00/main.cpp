/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvictor <elvictor@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 18:54:55 by elvictor          #+#    #+#             */
/*   Updated: 2026/10/22 20:07:02 by elvictor         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"

int main() {
    std::cout << "--- Valid Bureaucrats ---" << std::endl;
    try {
        Bureaucrat b1("Ivan", 1);
        std::cout << b1 << std::endl;

        Bureaucrat b2("Petr", 150);
        std::cout << b2 << std::endl;

        Bureaucrat b3("Stepan", 42);
        std::cout << b3 << std::endl;

        b3.incrementGrade();
        std::cout << "After increment: " << b3 << std::endl;
        
        b3.decrementGrade();
        std::cout << "After decrement: " << b3 << std::endl;

        b1.decrementGrade();
        std::cout << "After decrement: " << b1 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    
    std::cout << "\n--- Invalid Creation (Too High) ---" << std::endl;
    try {
        Bureaucrat high("TooHigh", 0);
        std::cout << high << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    
    std::cout << "\n--- Invalid Creation (Too Low) ---" << std::endl;
    try {
        Bureaucrat low("TooLow", 151);
        std::cout << low << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }


    std::cout << "\n--- Invalid Increment ---" << std::endl;
    try {
        Bureaucrat b("Maximus", 1);
        std::cout << b << std::endl;
        b.incrementGrade(); // Should throw
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n--- Invalid Decrement ---" << std::endl;
    try {
        Bureaucrat b("Minimum", 150);
        std::cout << b << std::endl;
        b.decrementGrade(); // Should throw
    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
