#pragma once
#include <string>
#include <boost/optional.hpp>
#include "Rotor.h"
#include "Reflector.h"

class ComponentsLibrary
{
public:
  static constexpr int LIBRARY_SIZE_ROTORS = 5;
  static constexpr int LIBRARY_SIZE_REFLECTORS = 3;
private:
  static const std::string ROTORS[LIBRARY_SIZE_ROTORS];
  static const std::string REFLECTORS[LIBRARY_SIZE_REFLECTORS];

public:
  Rotor createRotor(int id, int position, boost::optional<Rotor*> toKick) const;
  Reflector createReflector(int id) const;
};
