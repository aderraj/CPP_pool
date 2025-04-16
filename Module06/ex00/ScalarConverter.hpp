#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <limits>

typedef enum Scalartypes {
  CHAR,
  INT,
  FLOAT,
  DOUBLE,
  PSDO_FLOAT,
  PSDO_DOUBLE,
  UNKNOWN
} Scalartype;

class ScalarConverter {

  private:
    static void  convertToChar(const double& value);
    static void  convertToInt(const double& value);
    static void  convertToFloat(const double& value);
    static void  convertToDouble(const double& value);

  public:
    static void convert(const std::string& src);

};

#endif