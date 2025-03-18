#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
    try {
        // Create Bureaucrats
        Bureaucrat alice("Alice", 1);  // Highest grade
        Bureaucrat bob("Bob", 50);    // Mid-grade
        Bureaucrat charlie("Charlie", 150); // Lowest grade

        // Create Forms
        Form formA("FormA", 10, 20);  // Requires grade 10 to sign
        Form formB("FormB", 50, 100); // Requires grade 50 to sign
        Form formC("FormC", 150, 150); // Requires grade 150 to sign

        // Test signing forms
        alice.signForm(formA); // Should succeed
        bob.signForm(formA);   // Should fail (grade too low)
        bob.signForm(formB);   // Should succeed
        charlie.signForm(formC); // Should succeed
        charlie.signForm(formB); // Should fail (grade too low)

        // Print forms' status
        std::cout << formA << std::endl;
        std::cout << formB << std::endl;
        std::cout << formC << std::endl;

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}