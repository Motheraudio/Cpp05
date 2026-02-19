#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
  Bureaucrat ba("BureaucratA", 1);
  std::cout << ba << std::endl;
  Form fa("FormA", 2, 2);
  std::cout << fa << std::endl;
  ba.signForm(fa);
  std::cout << fa << std::endl;
  Bureaucrat bb("BureaucratB", 150);
  std::cout << bb << std::endl;
  Form fb("FormB", 2, 2);
  std::cout << fb << std::endl;
  bb.signForm(fb);
  std::cout << fb << std::endl;
  try
  {
    Form fc("Failed BureaucratC", 151, 1);
  }
  catch (std::exception &e)
  {
    std::cout << "CAUGHT EXCEPTION: " << e.what() << std::endl;
  }
  try
  {
    Form fd("Failed BureaucratD", 0, 1);
  }
  catch (std::exception &e)
  {
    std::cout << "CAUGHT EXCEPTION: " << e.what() << std::endl;
  }
  try
  {
    Form fe("Failed BureaucratE", 1, 151);
  }
  catch (std::exception &e)
  {
    std::cout << "CAUGHT EXCEPTION: " << e.what() << std::endl;
  }
  try
  {
    Form ff("Failed BureaucratF", 1, 0);
  }
  catch (std::exception &e)
  {
    std::cout << "CAUGHT EXCEPTION: " << e.what() << std::endl;
  }
}
