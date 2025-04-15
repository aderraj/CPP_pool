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
    static void  convertToChar(double& value);
    static void  convertToInt(double& value);
    static void  convertToFloat(double& value);
    static void  convertToDouble(double& value);

  public:
    static void convert(const std::string& src);

};

#endif