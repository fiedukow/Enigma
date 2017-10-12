#include "Enigma.h"
#include <boost/optional.hpp>

Enigma::Enigma(const Setup setup, const ComponentsLibrary& library)
  : plugBoard(setup.plugs), reflector(library.createReflector(setup.reflectorId))
{
  for (int i = 0; i < ROTOR_COUNT; ++i) {
    rotor.push_back(library.createRotor(setup.rotors[i], setup.positions[i], (i == 0 ? boost::optional<Rotor*>() : &rotor[i - 1])));
  }
}

std::string Enigma::scrumble(const std::string& input) {
  std::string result = input;
  for (size_t i = 0; i < input.size(); ++i) {
    result[i] = scrumble(input[i]);
  }
  return result;
}

char Enigma::scrumble(char c) {
  c = plugBoard.scrumble(c);
  rotor[0].rotate();
  for (int i = 0; i < ROTOR_COUNT; ++i) {
    c = rotor[i].scrumble(c);
  }

  c = reflector.scrumble(c);

  for (int i = ROTOR_COUNT - 1; i >= 0; --i) {
    c = rotor[i].unscrumble(c);
  }

  c = plugBoard.scrumble(c);

  return c;
}
