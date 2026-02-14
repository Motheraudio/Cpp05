#pragma once

#include "Bureaucrat.hpp"
#include <iostream>

class Form
{
public:
  Form();
  Form(const Form &obj);
  ~Form();
  void beSigned(Bureaucrat &who);
  Form &operator=(const Form &obj);

private:
  std::string const name;
  bool issigned;
  int signgrade;
  int executegrade;
};

std::ostream &operator<<(std::ostream &os, const Form &obj);
