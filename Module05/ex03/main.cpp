#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
  try {
      Bureaucrat alice("Alice", 1);          // highest rank
      Bureaucrat charlie("Charlie", 25);     // high-rank
      Bureaucrat bob("Bob", 140);            // low rank
      Bureaucrat dave("Dave", 150);          // lowest rank

      Intern intern;

      AForm* shrubForm = intern.makeForm("shrubbery creation", "home");
      AForm* roboForm = intern.makeForm("robotomy request", "Bender");
      AForm* pardonForm = intern.makeForm("presidential pardon", "Ford Prefect");

      // Invalid form
      AForm* invalidForm = intern.makeForm("invalid form", "target"); // Should print an error

      std::cout << "-----------------------------\n";

      // ShrubberyCreationForm
      if (shrubForm) {
          try {
              bob.signForm(*shrubForm); // Bob can sign this form
              alice.executeForm(*shrubForm); // Alice can execute this form
          } catch (std::exception& e) {
              std::cerr << e.what() << std::endl;
          }
          delete shrubForm;
      }

      std::cout << "-----------------------------\n";

      // RobotomyRequestForm
      if (roboForm) {
          try {
              charlie.signForm(*roboForm); // Charlie can sign this form
              charlie.executeForm(*roboForm); // Charlie can execute this form
          } catch (std::exception& e) {
              std::cerr << e.what() << std::endl;
          }
          delete roboForm;
      }

      std::cout << "-----------------------------\n";

      // PresidentialPardonForm
      if (pardonForm) {
          try {
              alice.signForm(*pardonForm); // Alice can sign this form
              alice.executeForm(*pardonForm); // Alice can execute this form
          } catch (std::exception& e) {
              std::cerr << e.what() << std::endl;
          }
          delete pardonForm;
      }

      std::cout << "-----------------------------\n";

      // invalid form
      if (!invalidForm) {
          std::cout << "Invalid form creation handled correctly.\n";
      }

  } catch (std::exception& e) {
      std::cerr << "Unhandled Exception: " << e.what() << std::endl;
  }

  return 0;
}