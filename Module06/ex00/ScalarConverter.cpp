#include "ScalarConverter.hpp"

bool  isInt(const std::string& str) {

  size_t i = (str[0] == '-' || str[0] == '+' ) ? 1 : 0;

  for (; i < str.length(); i++)
    if (!isdigit(str[i])) return (false);

  return (true);
}

Scalartype detectType(const std::string& literal) {

  size_t  len = literal.length();

  if (len <= 0)
    return UNKNOWN;
  if (len == 1 && !isdigit(literal[0]))
    return CHAR;
  if (literal == "nanf" || literal == "-inff" || literal == "+inff")
    return PSDO_FLOAT;
  if (literal == "nan" || literal == "-inf" || literal == "+inf")
    return PSDO_DOUBLE;
  if (literal.find('.') != std::string::npos) {
    if (literal[len - 1] == 'f') return FLOAT;
    else return DOUBLE;
  }
  if (isInt(literal))
    return INT;

  return UNKNOWN;
}

void  ScalarConverter::convertToChar(double& value) {
  std::cout << "char: ";
  if (std::isnan(value) || std::isinf(value)
    || value < std::numeric_limits<char>::min()
    || value > std::numeric_limits<char>::max())
    std::cout << "impossible";
  else if (!isprint(static_cast<char>(value)))
    std::cout << "Non displayable";
  else
    std::cout << "'" << static_cast<char>(value) << "'";
  std::cout << std::endl;
}

void  ScalarConverter::convertToInt(double& value) {

}

void  ScalarConverter::convertToFloat(double& value) {

}

void  ScalarConverter::convertToDouble(double& value) {

}

void  ScalarConverter::convert(const std::string& src) {

}