#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
class ShrubberyCreationForm : public AForm
{
public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &obj);
  ~ShrubberyCreationForm();
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);
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

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &obj);
