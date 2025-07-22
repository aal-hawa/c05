#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), target(target) {
	std::srand(std::time(NULL)); 
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	checkExecution(executor);
	std::cout << "Bzzzzzzzz.... DRILLING..." << std::endl;
	if (std::rand() % 2)
		std::cout << target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << target << "." << std::endl;
}