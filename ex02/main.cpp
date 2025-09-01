#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	try {
		Bureaucrat ahmad("Ahmad", 1);
		Bureaucrat ali("Ali", 140);


		std::cout << "----------------Test ShrubberyCreationForm-------------------" << std::endl;
	
		ShrubberyCreationForm shrubbery("Garden");
		std::cout << shrubbery << std::endl;
		ali.signForm(shrubbery);
		ahmad.executeForm(shrubbery);

		std::cout << "----------------Test RobotomyRequestForm---------------------" << std::endl;

		RobotomyRequestForm robotomy("Bender");
		std::cout << robotomy << std::endl;
		ahmad.signForm(robotomy);
		ahmad.executeForm(robotomy);

		std::cout << "----------------Test PresidentialPardonForm------------------" << std::endl;

		PresidentialPardonForm pardon("Arthur Dent");
		std::cout << pardon << std::endl;
		ahmad.signForm(pardon);
		ahmad.executeForm(pardon);

	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}