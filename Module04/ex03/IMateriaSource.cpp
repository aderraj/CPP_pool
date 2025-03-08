#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource() { }

IMateriaSource::IMateriaSource(const IMateriaSource& copy) { (void)copy; }

IMateriaSource&	IMateriaSource::operator=(const IMateriaSource& ref) { return ((void)ref, *this); }