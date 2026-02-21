#include "Bureaucrat.hpp"
#include "AForm.hpp"
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
  return "Grade too high";
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
  return "Grade too low";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
  if (grade > 150)
    throw(GradeTooLowException());
  if (grade < 1)
    throw(GradeTooHighException());
  this->grade = grade;
}

Bureaucrat::Bureaucrat() : name("James Default"), grade(67) {}
Bureaucrat::Bureaucrat(const Bureaucrat &other)
    : name(other.name), grade(other.grade){}
Bureaucrat::~Bureaucrat() {}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
  this->grade = obj.grade;
  return (*this);
}

std::string Bureaucrat::getName() const { return (this->name); }
int Bureaucrat::getGrade() const { return (this->grade); }
void Bureaucrat::increaseGrade()
{
  if (this->grade - 1 < 1)
    throw(GradeTooHighException());
  this->grade = this->grade - 1;
}
void Bureaucrat::decreaseGrade()
{
  if (this->grade + 1 > 150)
    throw(GradeTooLowException());
  this->grade = this->grade + 1;
}

void Bureaucrat::signForm(AForm &form)
{
  try
  {
    form.beSigned(*this);
    std::cout << this->getName() << " signed " << form.getFormName()
              << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << this->getName() << " couldn't sign " << form.getFormName()
              << " because " << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception &e)
	{
		std::cout << form.getFormName() << " couldn't be executed by " 
			<< this->getName() << " because " << e.what() << std::endl;
	}
}
std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
  os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
  return (os);
}
