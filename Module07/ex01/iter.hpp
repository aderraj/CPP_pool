#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void  iter(T *arr, size_t size, void (*f)(T const &)) {
  for (size_t i = 0; i < size; i++)
    f(arr[i]);
}


#endif