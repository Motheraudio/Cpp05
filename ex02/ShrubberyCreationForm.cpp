#include "ShrubberyCreationForm.hpp"
#include <fstream>
// const char *ShrubberyCreationForm::NoTargetException::what() const throw()
// {
//   return "No target! use the correct constructor";
// }
// ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Default", 145, 137){
// 	throw(NoTargetException());
// }
const char *ShrubberyCreationForm::NotSignedException::what() const throw()
{
	return ("The Shrubbery Creation Form is not signed");
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("Shrubbery Creation Form", 145, 137), target(target)
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

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getIfSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > 137)
		throw GradeTooLowException();
	else
	{
		std::ofstream out((this->target + "_shrubbery").c_str());
		out << "├── bin\n"
		<<"── boot\n"
		<<"│   └── grub\n"
		<<"│       ├── fonts\n"
		<<"│       └── locale\n"
		<<"├── cdrom\n"
		<<"└── dev\n"
		<<"    ├── block\n"
		<<"    ├── bsg\n"
		<<"    └── bus\n"
		<<"        └── usb\n"
		<<"            ├── 001\n"
		<<"            └── 002" << std::endl;
		out.close();
	}
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &obj)
{
  std::cout << "Form: " << obj.getFormName()
            << " Sign grade: " << obj.getSignGrade()
            << " Execute grade: " << obj.getExecuteGrade()
            << " Is it signed: " << obj.getIfSigned();
  return (os);
}
