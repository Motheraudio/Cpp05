#pragma once

#include <iostream>

class Bureaucrat {
public:
  Bureaucrat();
  Bureaucrat(const Bureaucrat& obj);
  virtual ~Bureaucrat();
  Bureaucrat& operator=(const Bureaucrat& obj);

  void getName();
  void getGrade();
  void increaseGrade(int amount);
  void decreaseGrade(int amount);

private:
  std::string name const;
  int grade;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat&obj);

