#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat a("Ahmad", 2);
		std::cout << a << std::endl;

		a.incrementGrade();
		std::cout << a << std::endl;

		a.incrementGrade(); // This should throw an exception
		std::cout << a << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat b("baraa", 151);
		std::cout << b << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}