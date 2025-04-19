#include "Identify.hpp"

Base* generate(void) {
  
  Base* (*derived[])() = { createA, createB, createC };
  return (derived[rand() % 3]());
}

void identify(Base* p) {
  std::cout << "it's type: ";
  if (dynamic_cast<A*>(p)) std::cout << "A";
  else if (dynamic_cast<B*>(p)) std::cout << "B";
  else if (dynamic_cast<C*>(p)) std::cout << "C";
  else std::cout << "Base";
  std::cout << std::endl;
}

void identify(Base& p) {
  std::cout << "it's type: ";
  try { (void)dynamic_cast<A&>(p); std::cout << "A";}
  catch (...) {
    try { (void)dynamic_cast<B&>(p); std::cout << "B";}
    catch (...) {
      try { (void)dynamic_cast<C&>(p); std::cout << "C";}
      catch (...) { std::cout << "Base"; }
    }
  }
  std::cout << std::endl;
}


Base* createA() { return (new A()); };
Base* createB() { return (new B()); };
Base* createC() { return (new C()); };