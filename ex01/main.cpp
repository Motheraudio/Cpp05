#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
  Bureaucrat ba("BureaucratA", 1);
  Form fa("FormA", 2, 2);
  std::cout << "Form A is signed?" << fa.getIfSigned() << std::endl;
  fa.beSigned(ba);
  std::cout << "Form A is signed?" << fa.getIfSigned() << std::endl;
}
