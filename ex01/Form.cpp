#include "Form.hpp"

Form::Form()
    : name("Default Form"), signgrade(67), executegrade(42), issigned(false)
{
}

const char *Form::GradeTooHighException::what() const throw()
{
  return "grade too high";
}
const char *Form::GradeTooLowException::what() const throw()
{
  return "grade too low";
}
Form::Form(std::string name, int signgrade, int executegrade)
    : name(name), issigned(false)
{
  if (signgrade < 1 || executegrade < 1) // this true?
    throw GradeTooHighException();
  if (signgrade > 150 || executegrade > 150) // this ture too?
    throw GradeTooLowException();
  this->signgrade = signgrade;
  this->executegrade = executegrade;
}

void Form::beSigned(Bureaucrat &who)
{
  if (who.getGrade() < this->signgrade)
    this->issigned = true;
  else
    // check subject, maybe throw exception
    return;
}
Form::Form(const Form &other) : name(other.name) { *this = other; }

Form::~Form() {}

Form &Form::operator=(const Form &obj)
{
  this->executegrade = obj.executegrade;
  this->signgrade = obj.signgrade;
  this->issigned = obj.issigned;
  return (*this);
}

std::string Form::getFormName() const { return this->name; }
int Form::getSignGrade() const { return this->signgrade; }
int Form::getExecuteGrade() const { return this->executegrade; }
bool Form::getIfSigned() const { return this->issigned; }
std::ostream &operator<<(std::ostream &os, const Form &obj) { return (os); }
