#include "PresidentialPardonForm.hpp"
// const char *PresidentialPardonForm::NoTargetException::what() const throw()
// {
//   return "No target! use the correct constructor";
// }
// PresidentialPardonForm::PresidentialPardonForm(): AForm("Default", 145, 137){
// 	throw(NoTargetException());
// }
const char *PresidentialPardonForm::NotSignedException::what() const throw()
{
	return ("The Presidential Pardon Form is not signed");
}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("Presidential Pardon Form", 25, 5), target(target)
{
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), target(other.target){
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj){
	this->target = obj.target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getIfSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > 5)
		throw GradeTooLowException();
	else
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &obj)
{
  std::cout << "Form: " << obj.getFormName()
            << " Sign gade: " << obj.getSignGrade()
            << " Execute grade: " << obj.getExecuteGrade()
            << " Is it signed: " << obj.getIfSigned();
  return (os);
}
