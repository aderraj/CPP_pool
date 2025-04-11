#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 1);          // highest rank
        Bureaucrat charlie("Charlie", 40);     // mid-rank
        Bureaucrat bob("Bob", 140);            // low rank
        Bureaucrat dave("Dave", 150);          // lowest rank

        // ShrubberyCreationForm (sign: 145, exec: 137)
				ShrubberyCreationForm shrubForm("home");
        try {
            bob.signForm(shrubForm); // Bob can sign this form
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        bob.executeForm(shrubForm); // Bob cannot execute this form (grade too low)
        alice.executeForm(shrubForm); // Alice can execute this form
        std::cout << "-----------------------------\n";

        // RobotomyRequestForm (sign: 72, exec: 45)
        RobotomyRequestForm roboForm("Bender");
        try {
            charlie.signForm(roboForm); // Charlie can sign this form
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl; 
        }
        charlie.executeForm(roboForm); // Charlie can execute this form
        bob.executeForm(roboForm); // Bob cannot execute this form (grade too low)
        std::cout << "-----------------------------\n";

        // PresidentialPardonForm (sign: 25, exec: 5)
        PresidentialPardonForm pardonForm("Ford Prefect");
        try {
            alice.signForm(pardonForm); // Alice can sign this form
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        alice.executeForm(pardonForm); // Alice can execute this form
        charlie.executeForm(pardonForm); // Charlie cannot execute this form (grade too low)
        std::cout << "-----------------------------\n";

        // Test unsigned form execution
        ShrubberyCreationForm notSignedForm("garden");
        bob.executeForm(notSignedForm); // Should throw NotSignedException
        std::cout << "-----------------------------\n";

        // Test assigning forms to multiple Bureaucrats
        ShrubberyCreationForm sharedForm("shared");
        try {
            dave.signForm(sharedForm); // Dave cannot sign this form (grade too low)
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
        try {
            bob.signForm(sharedForm); // Bob can sign this form
            alice.executeForm(sharedForm); // Alice can execute this form
        } catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }

    } catch (std::exception& e) {
        std::cerr << "Unhandled Exception: " << e.what() << std::endl;
    }

    return 0;
}