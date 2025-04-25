#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>
#include <algorithm>
#include <limits.h>
#include <exception>

class Span {

  private:
    Span();
    unsigned int max_size;
    std::multiset<int> holder;

  public:
    Span(unsigned int max);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();
    int  shortestSpan();
    int  longestSpan();
    void addNumber(int n);
    template <typename T>
    void addNumbers(T start, T end) {
        if (std::distance(start, end) + holder.size() > max_size)
          throw std::length_error("Not enough space!");
        holder.insert(start, end);
    }

};

#endif