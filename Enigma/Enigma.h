#pragma once
#include <map>
#include <vector>
#include "ComponentsLibrary.h"
#include "Rotor.h"
#include "PlugBoard.h"

class Enigma
{
  static constexpr int ROTOR_COUNT = 3;
public:
  struct Setup {
    int rotors[ROTOR_COUNT]; // id of selected rotors
    int positions[ROTOR_COUNT]; // positions of selected rotors;
    int reflectorId;
    std::map<char, char> plugs;
  };

private:  
  std::vector<Rotor> rotor;
  Reflector reflector;
  PlugBoard plugBoard;  

public:
  Enigma(Setup setup, const ComponentsLibrary& library);

  std::string scrumble(const std::string&);
  char scrumble(char c);
};