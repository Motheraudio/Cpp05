#pragma once

#include "Bureaucrat.hpp"
#include <iostream>

class AForm
{
public:
  AForm();
  AForm(std::string name, int signgrade, int executegrade);
  AForm(const AForm &obj);
  virtual ~AForm();
  AForm &operator=(const AForm &obj);

  class GradeTooHighException : public std::exception
  {
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception
  {
    const char *what() const throw();
  };

  void beSigned(Bureaucrat &who);
  std::string getFormName() const;
  int getSignGrade() const;
  int getExecuteGrade() const;
  bool getIfSigned() const;

private:
  std::string const name;
  bool issigned;
  int signgrade;
  int executegrade;
};

std::ostream &operator<<(std::ostream &os, const AForm &obj);
