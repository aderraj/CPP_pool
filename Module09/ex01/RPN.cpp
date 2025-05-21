#include "RPN.hpp"

std::string getField(std::stringstream& input) {
  std::string field;

  std::getline(input, field, ' ');
  return (field); 
}

long  calculate(int x, int y, char op) {
  switch (op)
  {
  case '+':
    return (x + y);
  case '-':
    return (x - y);
  case '*':
    return (x * y);
  case '/':
    if (!y)
      throw std::logic_error("invalid division by 0!");
    return (x / y);
  default:
    throw std::runtime_error("invalid operator!");
    break;
  }
}

void  rpn(const char* exp) {
  std::stringstream s(exp);
  std::string f;
  std::stack<int> numbers;
  long  result = 0;

  while ( !(f = getField(s)).empty() ) {
    if (f == "*" || f == "+" || f == "-" || f == "/") {
      if (!numbers.size())
        throw std::runtime_error("invalid input!");
      int y = numbers.top();
      numbers.pop();
      if (!numbers.size())
        throw std::runtime_error("Error: Invalid operation!");
      result = calculate(numbers.top(), y, f[0]);
      numbers.pop();
      numbers.push(result);
    }
    else if (f.find_first_not_of("0123456789") == std::string::npos)
      numbers.push(atoi(f.c_str()));
    else
      throw std::runtime_error("Error: invalid syntax!");
  }
  std::cout << result << std::endl;
}