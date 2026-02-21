#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
class RobotomyRequestForm : public AForm
{
public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &obj);
  ~RobotomyRequestForm();
  RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);
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

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &obj);
