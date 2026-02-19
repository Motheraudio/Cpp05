#include "AForm.hpp"

AForm::AForm()
    : name("Default AForm"), issigned(false), signgrade(67), executegrade(42)
{
}

const char *AForm::GradeTooHighException::what() const throw()
{
  return "grade too high";
}
const char *AForm::GradeTooLowException::what() const throw()
{
  return "grade too low";
}
AForm::AForm(std::string name, int signgrade, int executegrade)
    : name(name), issigned(false)
{
  if (signgrade < 1 || executegrade < 1)
    throw GradeTooHighException();
  if (signgrade > 150 || executegrade > 150)
    throw GradeTooLowException();
  this->signgrade = signgrade;
  this->executegrade = executegrade;
}

void AForm::beSigned(Bureaucrat &who)
{
  if (who.getGrade() <= this->signgrade)
    this->issigned = true;
  else
    throw GradeTooLowException();
}
AForm::AForm(const AForm &other) : name(other.name) { *this = other; }

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &obj)
{
  this->executegrade = obj.executegrade;
  this->signgrade = obj.signgrade;
  this->issigned = obj.issigned;
  return (*this);
}

std::string AForm::getAFormName() const { return this->name; }
int AForm::getSignGrade() const { return this->signgrade; }
int AForm::getExecuteGrade() const { return this->executegrade; }
bool AForm::getIfSigned() const { return this->issigned; }
std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
  std::cout << "Form: " << obj.getAFormName()
            << " Sign gade: " << obj.getSignGrade()
            << " Execute grade: " << obj.getExecuteGrade()
            << " Is it signed: " << obj.getIfSigned();
  return (os);
}
