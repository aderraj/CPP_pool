#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {

  private:
    T     *ptr;
    size_t len;

  public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array&  operator=(const Array& other);
    T& operator[](size_t idx);
    ~Array();
    size_t  size() const;

};

#include "Array.tpp"

#endif