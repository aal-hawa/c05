#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	try {
		Bureaucrat ahmad("Ahmad", 1); // High rank: can sign and execute anything
		Bureaucrat ali("Ali", 140);   // Can only sign simple forms


		std::cout << "----------------Test ShrubberyCreationForm-------------------" << std::endl;
	
		ShrubberyCreationForm shrubbery("Garden");
		std::cout << shrubbery << std::endl;
		ali.signForm(shrubbery); // Should succeed
		ahmad.executeForm(shrubbery); // Ahmad executes

		std::cout << "----------------Test RobotomyRequestForm---------------------" << std::endl;

		RobotomyRequestForm robotomy("Bender");
		std::cout << robotomy << std::endl;
		ahmad.signForm(robotomy); // Ahmad signs
		ahmad.executeForm(robotomy); // Ahmad executes

		std::cout << "----------------Test PresidentialPardonForm------------------" << std::endl;

		PresidentialPardonForm pardon("Arthur Dent");
		std::cout << pardon << std::endl;
		ahmad.signForm(pardon); // Ahmad signs
		ahmad.executeForm(pardon); // Ahmad executes

	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}