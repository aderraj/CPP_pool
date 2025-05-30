#ifndef IDENTIFY_HPP
#define IDENTIFY_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base {
  
  public:
    virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void);
void  identify(Base* p);
void  identify(Base& p);

Base* createA();
Base* createB();
Base* createC();

#endif