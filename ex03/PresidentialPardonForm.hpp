#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
class PresidentialPardonForm : public AForm
{
public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string &target);
  PresidentialPardonForm(const PresidentialPardonForm &obj);
  ~PresidentialPardonForm();
  PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
  void execute(Bureaucrat const & executor) const;
  // class NoTargetException : public std::exception
  // {
  //   const char *what() const throw();
  // };
  class NotSignedException: public std::exception
	{
		const char *what() const throw();
	};
private:
  std::string target;
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &obj);
