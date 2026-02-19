#pragma once

#include <iostream>

class PresidentialPardonForm {
public:
  PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm& obj);
  ~PresidentialPardonForm();

  PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);

private:
  // TODO: add members
};

std::ostream&	operator<<(std::ostream& os, const PresidentialPardonForm&obj);

