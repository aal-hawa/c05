#include "Form.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw GradeTooHighException();
	if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form &other)
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw GradeTooHighException();
	if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw GradeTooLowException();
}

Form &Form::operator=(const Form &other) {
	if (this != &other)
		isSigned = other.isSigned;
	return *this;
}

const std::string &Form::getName() const {
	return name;
}

bool Form::getIsSigned() const {
	return isSigned;
}

int Form::getGradeToSign() const {
	return gradeToSign;
}

int Form::getGradeToExecute() const {
	return gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (isSigned)
		return;
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Form grade too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Form grade too low!";
}

std::ostream &operator<<(std::ostream &out, const Form &form) {
	out << "Form: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< ", Grade to Sign: " << form.getGradeToSign()
		<< ", Grade to Execute: " << form.getGradeToExecute();
	return out;
}
