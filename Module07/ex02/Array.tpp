#include "Array.hpp"

template <typename T>
Array<T>::Array() : ptr(new T[0]), len(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : ptr(new T[n]), len(n) {}

template<typename T>
Array<T>::Array(const Array& other) : ptr(new T[other.len]), len(other.len) {
  for (size_t i = 0; i < len; i++)
    ptr[i] = other.ptr[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
  if (this != &other) {
    delete[] ptr;
    ptr = new T[len];
    for (size_t i = 0; i < len; i++) ptr[i] = other.ptr[i];
  }
  return (*this);
}

template<typename T>
T& Array<T>::operator[](size_t idx) {
  if (idx >= len)
    throw std::exception();
  return ptr[idx];
}

template<typename T>
Array<T>::~Array() { delete[] ptr; }

template<typename T>
size_t  Array<T>::size() const { return len; }