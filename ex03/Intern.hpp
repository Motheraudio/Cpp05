#pragma once

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
class Intern {
public:
  Intern();
  Intern(const Intern& obj);
  ~Intern();
  Intern& operator=(const Intern& obj);

  AForm *makeForm(const std::string &formname, const std::string &formtarget);
private:
	std::string names[3];
  AForm *createPresidentialPardon(const std::string &formtarget);
  AForm *createRobotomyRequestForm(const std::string &formtarget);
  AForm *createShrubberyCreationForm(const std::string &formtarget);
};

