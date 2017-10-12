#include "Reflector.h"

Reflector::Reflector(const std::string & combination)
  : combination(combination)
{}

char Reflector::scrumble(char c) const
{
  return combination[c - 'A'];
}
