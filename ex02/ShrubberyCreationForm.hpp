#pragma once

#include "AForm.hpp"
#include <iostream>
class ShrubberyCreationForm : public AForm
{
public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &obj);
  ~ShrubberyCreationForm();
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);

  class NoTargetException : public std::exception
  {
    const char *what() const throw();
  };
private:
  std::string target;
};

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &obj);
