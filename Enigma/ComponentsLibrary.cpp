#include "ComponentsLibrary.h"
#include <cassert>
#include <boost/optional.hpp>

const std::string ComponentsLibrary::ROTORS[ComponentsLibrary::LIBRARY_SIZE_ROTORS] =
{
  "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
  "AJDKSIRUXBLHWTMCQGZNPYFVOE",
  "BDFHJLCPRTXVZNYEIWGAKMUSQO",
  "ESOVPZJAYQUIRHXLNFTGKDCMWB",
  "VZBRGITYUPSDNHLXAWMJQOFECK"
};

const std::string ComponentsLibrary::REFLECTORS[LIBRARY_SIZE_REFLECTORS] =
{
  "EJMZALYXVBWFCRQUONTSPIKHGD",
  "YRUHQSLDPXNGOKMIEBFZCWVJAT",
  "FVPJIAOYEDRZXWGCTKUQSBNMHL"
};


Rotor ComponentsLibrary::createRotor(int id, int position, boost::optional<Rotor*> toKick = boost::optional<Rotor*>()) const
{
  assert(position <= 25 && position >= 0);
  assert(id >= 0 && id < LIBRARY_SIZE_ROTORS);

  return Rotor(ROTORS[id], position, toKick);
}

Reflector ComponentsLibrary::createReflector(int id) const
{
  assert(id >= 0 && id < LIBRARY_SIZE_REFLECTORS);
  return Reflector(REFLECTORS[id]);
}
