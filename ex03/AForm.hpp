#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	protected:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;

	public:
		AForm();
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		virtual ~AForm();

		AForm(const AForm &other);
		AForm &operator=(const AForm &other);

		const std::string &getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat &bureaucrat);
		void checkExecution(const Bureaucrat &executor) const;
		
		virtual void execute(const Bureaucrat &executor) const = 0; 

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw();
		};
	};

	std::ostream &operator<<(std::ostream &out, const AForm &form);

	#endif