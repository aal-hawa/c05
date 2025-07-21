#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat b("Ahmad", 40);
		Form f("Tax Form", 50, 20);

		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;

		Bureaucrat d("Ali", 70);
		Form n("Tax Form", 50, 20);
		std::cout << n << std::endl;
		d.signForm(n);
		std::cout << n << std::endl;

	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}