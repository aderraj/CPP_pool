#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <limits>
#include <climits>
#include <regex.h>

# define CHAR_PATTERN "^.$"
# define INT_PATTERN "^[-+]?[0-9]+$"
# define FLOAT_PATTERN "^[-+]?[0-9]*\\.?[0-9]+f$"
# define DOUBLE_PATTERN "^[-+]?[0-9]*\\.?[0-9]+$"
# define PSDOF_PATTERN "^(nanf|[-+]?inff)$"
# define PSDOD_PATTERN "^(nan|[-+]?inf)$"
# define RED "\x1b[91m"
# define RESET "\x1b[0m"

class ScalarConverter {

  private:
    static void  convertToChar(const double& value);
    static void  convertToInt(const double& value);
    static void  convertToFloat(const double& value);
    static void  convertToDouble(const double& value);

  public:
    static void convert(const std::string& src);

};

bool isValidLiteral(const std::string& literal);

#endif