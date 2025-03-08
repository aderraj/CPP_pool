#include "ICharacter.hpp"

ICharacter::ICharacter() { }

ICharacter::ICharacter(const ICharacter& copy) { (void)copy; }

ICharacter&	ICharacter::operator=(const ICharacter& ref) { return ((void)ref, *this);}
