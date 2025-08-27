#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("DefaultTarget") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	checkExecution(executor);
	std::ofstream out((target + "_shrubbery").c_str());
	if (!out.is_open())
	{
		std::cerr << "Failed to open the " << target << "_shrubbery" << std::endl;
		return;
	}
	// out << "ASCII TREES 🌲🌲🌲" << std::endl;
	out << "       _-_       " << std::endl;
	out << "    /~~   ~~\\    " << std::endl;
	out << " /~~         ~~\\ " << std::endl;
	out << "{               }" << std::endl;
	out << " \\  _-     -_  / " << std::endl;
	out << "   ~  \\\\ //  ~   " << std::endl;
	out << "_- -   | | _- _  " << std::endl;
	out << "  _ -  | |   -_  " << std::endl;
	out << "      // \\\\      " << std::endl;
	out.close();
}