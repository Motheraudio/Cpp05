#include "RobotomyRequestForm.hpp"
#include <cstdlib>
// const char *RobotomyRequestForm::NoTargetException::what() const throw()
// {
//   return "No target! use the correct constructor";
// }
// RobotomyRequestForm::RobotomyRequestForm(): AForm("Default", 145, 137){
// 	throw(NoTargetException());
// }
const char *RobotomyRequestForm::NotSignedException::what() const throw()
{
	return ("The Robotomy Request Form is not signed");
}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("Robotomy Request Form", 72, 45), target(target)
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), target(other.target){
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj){
	this->target = obj.target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getIfSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > 45)
		throw GradeTooLowException();
	else
	{
		std::cout << "*BZZZZZZZZZZZZZZZ*" << std::endl;
		std::srand(time(NULL));
		int randval = std::rand();
		if (randval % 2 == 1)
			std::cout << this->target << " Has been robotomized succesfully!" << std::endl;
		else
			std::cout << this->target <<"'s robotomy failed." << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &obj)
{
  std::cout << "Form: " << obj.getFormName()
            << " Sign grade: " << obj.getSignGrade()
            << " Execute grade: " << obj.getExecuteGrade()
            << " Is it signed: " << obj.getIfSigned();
  return (os);
}
