#pragma once

#include <iostream>

class RobotomyRequestForm {
public:
  RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm& obj);
  ~RobotomyRequestForm();

  RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);

private:
  // TODO: add members
};

std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm&obj);

