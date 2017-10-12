#pragma once
#include <string>

class Reflector
{
private:
  const std::string combination;

public:
  Reflector(const std::string& combination);
  char scrumble(char c) const;
};