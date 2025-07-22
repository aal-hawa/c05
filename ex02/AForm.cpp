#include "AForm.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}

AForm::AForm(const AForm &other)
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other)
		isSigned = other.isSigned;
	return *this;
}

const std::string &AForm::getName() const {
	return name;
}

bool AForm::getIsSigned() const {
	return isSigned;
}

int AForm::getGradeToSign() const {
	return gradeToSign;
}

int AForm::getGradeToExecute() const {
	return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (isSigned)
		return;
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

void AForm::checkExecution(const Bureaucrat &executor) const {
	if (!isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Form grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Form grade too low!";
}

const char *AForm::FormNotSignedException::what() const throw() {
	return "Form not signed!";
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
	out << "Form: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< ", Grade to Sign: " << form.getGradeToSign()
		<< ", Grade to Execute: " << form.getGradeToExecute();
	return out;
}
