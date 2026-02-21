#include "Intern.hpp"	

Intern::Intern(){
	this->names[0] = "shrubbery creation";
	this->names[1] = "robotomy request";
	this->names[2] = "presidential pardon";
}

Intern::Intern(const Intern& other){
	*this = other;
}

Intern::~Intern(){

}

Intern& Intern::operator=(const Intern& obj){
	this->names[0] = obj.names[0];
	this->names[1] = obj.names[1];
	this->names[2] = obj.names[2];
return (*this);
}
AForm *Intern::createPresidentialPardon(const std::string &formtarget)
{
	return new PresidentialPardonForm(formtarget);
}
AForm *Intern::createRobotomyRequestForm(const std::string &formtarget)
{

	return new RobotomyRequestForm(formtarget);
}
AForm *Intern::createShrubberyCreationForm(const std::string &formtarget)
{
	return new ShrubberyCreationForm(formtarget);

}
AForm *Intern::makeForm(const std::string &formname, const std::string &formtarget)
{
	AForm* (Intern::*f[3])(const std::string&) = { &Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardon}; 
	for (int i = 0; i < 3; i++)
	{
		if (this->names[i] == formname)
		{
			std::cout << "Intern creates " << formname << std::endl;
			return ((this->*f[i])(formtarget));
		}
	}
	std::cout << formname << " Does not exist. No form created." << std::endl;
	return (NULL);
}

