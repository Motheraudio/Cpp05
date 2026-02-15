#pragma once

#include "Bureaucrat.hpp"
#include <iostream>

class Form
{
public:
  Form();
  Form(std::string name, int signgrade, int executegrade);
  Form(const Form &obj);
  ~Form();
  Form &operator=(const Form &obj);

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

std::ostream &operator<<(std::ostream &os, const Form &obj);
