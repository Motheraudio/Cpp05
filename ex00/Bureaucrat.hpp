#pragma once

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat
{
public:
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat();
  Bureaucrat(const Bureaucrat &obj);
  virtual ~Bureaucrat();
  Bureaucrat &operator=(const Bureaucrat &obj);
  class GradeTooHighException : public std::exception
  {
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception
  {
    const char *what() const throw();
  };
  std::string getName() const;
  int getGrade() const;
  void increaseGrade();
  void decreaseGrade();

private:
  const std::string name;
  int grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);
