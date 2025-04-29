#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>

template <typename T, class container = std::deque<T> >
class MutantStack : public std::stack<T> {
  public :
    MutantStack() : std::stack<T, container>() {}
    MutantStack(const MutantStack& other) : std::stack<T, container>(other) {}
    MutantStack& operator=(const MutantStack& other) {
      if (this != &other)
        std::stack<T>::operator=(other);
      return (*this);
    }
    ~MutantStack() {}
    
    typedef typename container::iterator iterator;

    iterator begin(void) { return (this->c.begin()); }
    iterator end(void) { return (this->c.end()); }
    iterator rbegin(void) { return (this->c.rbegin()); }
    iterator rend(void) { return (this->c.rend()); }
    const iterator cbegin(void) { return (this->c.cbegin()); }
    const iterator cend(void) { return (this->c.cend()); }
    const iterator crbegin(void) { return (this->c.crbegin()); }
    const iterator crend(void) { return (this->c.crend()); }
};

#endif