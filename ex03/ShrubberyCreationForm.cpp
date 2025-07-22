#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	checkExecution(executor);
	std::ofstream out((target + "_shrubbery").c_str());
	out << "ASCII TREES 🌲🌲🌲" << std::endl;
	out.close();
}