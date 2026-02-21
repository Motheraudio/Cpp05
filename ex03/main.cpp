#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	Intern someRandomIntern;
	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << rrf->getFormName() << std::endl;
	// AForm hehe;
	// Bureaucrat ba("Bureaucrat A", 150);
	// std::cout << ba << std::endl;
	// Bureaucrat bb("Bureaucrat A", 1);
	// std::cout << bb << std::endl;
	// ShrubberyCreationForm fa("this");
	// std::cout << fa << std::endl;
	// ba.executeForm(fa);
	// ba.signForm(fa);
	// bb.signForm(fa);
	// std::cout << fa << std::endl;
	// ba.executeForm(fa);
	// bb.executeForm(fa);
	// RobotomyRequestForm fb("john");
	// std::cout << fb << std::endl;
	// ba.executeForm(fb);
	// ba.signForm(fb);
	// bb.signForm(fb);
	// std::cout << fb << std::endl;
	// ba.executeForm(fb);
	// bb.executeForm(fb);
	// PresidentialPardonForm fc("juan");
	// std::cout << fc << std::endl;
	// ba.executeForm(fc);
	// ba.signForm(fc);
	// bb.signForm(fc);
	// std::cout << fc << std::endl;
	// ba.executeForm(fc);
	// bb.executeForm(fc);
}
