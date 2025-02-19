#include "Weapon.hpp"

Weapon::Weapon( std::string _type) : type(_type) {}

const std::string& Weapon::getType( void ) { return (type); }

void	Weapon::setType( std::string _new ) { type = _new; }