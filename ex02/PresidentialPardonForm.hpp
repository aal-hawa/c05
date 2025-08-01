#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class PresidentialPardonForm  : public AForm {
	private:
		std::string target;

	public:
		PresidentialPardonForm (const std::string &target);
		~PresidentialPardonForm ();
		void execute(const Bureaucrat &executor) const;
};	

#endif