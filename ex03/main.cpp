#include "Intern.hpp"
#include "Bureaucrat.hpp"


int main() {
	try {
		Intern someIntern;
		
		Bureaucrat ahmad("Ahmad", 1); 

		std::cout << "----------------Test form1---------------------" << std::endl;
		AForm* form1 = someIntern.makeForm("shrubbery creation", "Home");
		if (form1) {
			ahmad.signForm(*form1);
			ahmad.executeForm(*form1);
			delete form1; 
		}

		std::cout << "----------------Test form2---------------------" << std::endl;
		AForm* form2 = someIntern.makeForm("robotomy request", "Bender");
		if(form2) {
			ahmad.signForm(*form2);
			ahmad.executeForm(*form2);
			delete form2; 
		}

		std::cout << "----------------Test form3---------------------" << std::endl;
		AForm* form3 = someIntern.makeForm("presidential pardon", "Arthur Dent");
		if(form3) {
			ahmad.signForm(*form3);
			ahmad.executeForm(*form3);
			delete form3; 
		}

		std::cout << "----------------Test form4---------------------" << std::endl;
		AForm* form4 = someIntern.makeForm("invalid form", "Nobody");
		if(form4)
			delete form4;

	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	return 0;
}