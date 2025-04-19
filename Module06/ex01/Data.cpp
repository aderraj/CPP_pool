#include "Data.hpp"

Data::Data() : x(42) {}

Data::Data(const Data& other) : x(other.x) {}

Data& Data::operator=(const Data& other) {
  if (this != &other)
    x = other.x;
  return (*this);
}

Data::~Data() {}
