#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator  easyfind(T& cont, int n) {
  typename T::iterator i = std::find(cont.begin(), cont.end(), n);
  if (i == cont.end())
    throw std::out_of_range("Not found");
  return (i);
}

#endif