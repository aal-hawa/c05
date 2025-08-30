#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
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


	struct FormEntry {
		std::string name;
		AForm* (*create)(const std::string& target);
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