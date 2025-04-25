#include "Span.hpp"
#include <iterator>
Span::Span() : max_size(0) {}

Span::Span(unsigned int max) :
  max_size(max){}

Span::Span(const Span& other) :
  max_size(other.max_size),
  holder(other.holder) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
  if (this != &other) {
    holder = other.holder;
    max_size = other.max_size;
  }
  return (*this);
}

void Span::addNumber(int n) {
  if (max_size <= holder.size())
    throw std::length_error("Span is full!");
  holder.insert(n);
}

int  Span::shortestSpan() {
  if (holder.size() < 2)
    throw std::length_error("Too small Span!");

  int shortest = INT_MAX;
  std::multiset<int>::iterator prev = holder.begin();
  std::multiset<int>::iterator i = ++holder.begin();
  for (; i != holder.end(); i++) {
    int d = *i - *prev;
    if (d < shortest)
      shortest = d;
    prev = i;
  }
  return (shortest);
}

int  Span::longestSpan() {
  if (holder.size() < 2)
    throw std::length_error("Too small Span!");

  return (*(--holder.end()) - *holder.begin());
}
