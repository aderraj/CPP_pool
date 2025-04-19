#include "ScalarConverter.hpp"

void  ScalarConverter::convertToChar(const double& value) {
  std::cout << "char: ";
  if (std::isnan(value) || std::isinf(value)
      || value < CHAR_MIN || value > CHAR_MAX)
    std::cout << "impossible";
  else if (!isprint(static_cast<char>(value)))
    std::cout << "Non displayable";
  else
    std::cout << "'" << static_cast<char>(value) << "'";
  std::cout << std::endl;
}

void  ScalarConverter::convertToInt(const double& value) {
  std::cout << "int: ";
  if (std::isnan(value) || std::isinf(value)
      || value < std::numeric_limits<int>::min()
      || value > std::numeric_limits<int>::max())
    std::cout << "impossible";
  else
    std::cout << static_cast<int>(value);
  std::cout << std::endl;
}

void  ScalarConverter::convertToFloat(const double& value) {
  std::cout << "float: ";
  if (std::isnan(value) || std::isinf(value))
    std::cout << value << "f";
  else if (value <= -std::numeric_limits<float>::max()
      || value > std::numeric_limits<float>::max())
    std::cout << "impossible";
  else {
    std::cout << std::fixed << std::setprecision(1) <<
    static_cast<float>(value);
    std::cout << "f";
  }
  std::cout << std::endl;
}

void  ScalarConverter::convertToDouble(const double& value) {
  std::cout << "double: ";
  if (std::isnan(value) || std::isinf(value))
    std::cout << value;
  else if (value <= -std::numeric_limits<double>::max()
      || value > std::numeric_limits<double>::max())
    std::cout << "impossible";
  else
      std::cout << std::fixed << value;
  std::cout << std::endl;
}

bool  regexMatch(const std::string& str, const char* pattern) {

  regex_t regex;

  int result = regcomp(&regex, pattern, REG_EXTENDED);
  if (result != 0) {
      std::cerr << "Error: Failed to compile regex pattern." << std::endl;
      return false;
  }
  result = regexec(&regex, str.c_str(), 0, NULL, 0);
  regfree(&regex);

  return (result == 0);
}


bool isValidLiteral(const std::string& literal) {
  return regexMatch(literal, CHAR_PATTERN) ||
         regexMatch(literal, INT_PATTERN) ||
         regexMatch(literal, FLOAT_PATTERN) ||
         regexMatch(literal, DOUBLE_PATTERN) ||
         regexMatch(literal, PSDOF_PATTERN) ||
         regexMatch(literal, PSDOD_PATTERN);
}

void  ScalarConverter::convert(const std::string& src) {
  double value;
  if (src.length() == 1 && !isdigit(src[0]))
    value = static_cast<double>(src[0]);
  else 
    value = strtod(src.c_str(), NULL);
  ScalarConverter::convertToChar(value);
  ScalarConverter::convertToInt(value);
  ScalarConverter::convertToFloat(value);
  ScalarConverter::convertToDouble(value);
}