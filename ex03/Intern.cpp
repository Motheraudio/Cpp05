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

AForm *Intern::makeForm(const std::string &formname, const std::string &formtarget)
{
	*this->forms[0] = ShrubberyCreationForm(formtarget);
	*this->forms[1] = RobotomyRequestForm(formtarget);
	*this->forms[2] = PresidentialPardonForm(formtarget);
	for (int i = 0; i < 3; i++)
		if (this->names[i] == formname)
		{
			std::cout << "Intern creates " << formname << std::endl;
			return (this->forms[i]);
		}
	std::cout << formname << " Does not exist. No form created." << std::endl;
	return (NULL);
}

