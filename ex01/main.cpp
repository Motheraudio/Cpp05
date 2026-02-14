#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
  Bureaucrat a("Carlos", 1);
  std::cout << a << std::endl;
  try
  {
    a.increaseGrade();
    std::cout << "Increase Grade Carlos" << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << "EXCEPTIONCarlos: " << e.what() << std::endl;
  }
  Bureaucrat b("Carla", 150);
  std::cout << b << std::endl;
  try
  {
    b.decreaseGrade();
    std::cout << "Decrease Grade Carla" << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << "EXCEPTIONCarla: " << e.what() << std::endl;
  }
  Bureaucrat c("Charles", 67);
  std::cout << c << std::endl;
  c.getName();
  try
  {
    c.increaseGrade();
    std::cout << "increasing Charles" << std::endl;
    std::cout << c << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << "EXCEPTIONCharles: " << e.what() << std::endl;
  }
  try
  {
    c.decreaseGrade();
    std::cout << "decreasing Charles" << std::endl;
    std::cout << c << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << "EXCEPTIONCharles: " << e.what() << std::endl;
  }
  std::cout << "Creating too low grade object" << std::endl;
  try
  {
    Bureaucrat x("Charlotte", 151);
  }
  catch (std::exception &e)
  {
    std::cout << "EXCEPTIONCharlotte: " << e.what() << std::endl;
  }
  std::cout << "Creating too high grade object" << std::endl;
  try
  {
    Bureaucrat z("Charlie", 0);
  }
  catch (std::exception &e)
  {
    std::cout << "EXCEPTIONCharlie: " << e.what() << std::endl;
  }
}
