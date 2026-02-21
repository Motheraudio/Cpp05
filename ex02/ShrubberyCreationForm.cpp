#include "ShrubberyCreationForm.hpp"

const char *ShrubberyCreationForm::NoTargetException::what() const throw()
{
  return "No target! use the correct constructor";
}
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Default", 145, 137){
	throw(NoTargetException());
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string &target): AForm("Shrubbery Creation Form", 145, 137), target(target)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), target(other.target){
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj){
	this->target = obj.target;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const ShrubberyCreationForm&obj){
	return(os << );
}
