#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern& other) {
	(void)other; // Unused parameter
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this; // No specific assignment logic needed
}

static AForm* createShrubbery(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
	return new RobotomyRequestForm(target);
}
static AForm* createPresidential(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	typedef AForm* (*FormCreator)(const std::string& target);


	struct FormEntry {
		std::string name;
		FormCreator create;
	};
	FormEntry forms[] = {
		{"shrubbery creation", &createShrubbery},
		{"robotomy request", &createRobotomy},
		{"presidential pardon", &createPresidential}
	};
	

	for(int i = 0; i < 3; ++i) {
		if (forms[i].name == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i].create(target);
		}
	}
	std::cerr << "Form name \"" << formName << "\" is unknown." << std::endl;
	return NULL; 
}