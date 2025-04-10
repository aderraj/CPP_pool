#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat alice("Alice", 1);          // highest rank
        Bureaucrat bob("Bob", 140);            // low rank
        Bureaucrat charlie("Charlie", 50);     // mid-rank

        // Shrubbery Form (sign: 145, exec: 137)
        ShrubberyCreationForm shrubForm("home");
        bob.signForm(shrubForm);
        shrubForm.execute(bob); // should succeed

        std::cout << "-----------------------------\n";

        // Robotomy Form (sign: 72, exec: 45)
        RobotomyRequestForm roboForm("Bender");
        charlie.signForm(roboForm);
        charlie.executeForm(roboForm); // should succeed or fail randomly

        std::cout << "-----------------------------\n";

        // Presidential Pardon Form (sign: 25, exec: 5)
        PresidentialPardonForm pardonForm("Ford Prefect");
        alice.signForm(pardonForm);
        alice.executeForm(pardonForm); // should succeed

        std::cout << "-----------------------------\n";

        // Attempt to execute without signing
        ShrubberyCreationForm notSignedForm("garden");
        bob.executeForm(notSignedForm); // should throw NotSignedException

    } catch (std::exception& e) {
        std::cerr << "Unhandled Exception: " << e.what() << std::endl;
    }

    return 0;
}
