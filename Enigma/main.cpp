#include <iostream>
#include <map>
#include "ComponentsLibrary.h"
#include "Enigma.h"

int main(int argc, char** argv) {
  //std::cout << "Usage: " << argv[0] << " SETUP_FILE CODE_FILE" << std::endl;
  ComponentsLibrary library;
  std::map<char, char> plugs = {
    { 'B', 'F' },
    { 'S', 'D' },
    { 'A', 'Y' },
    { 'H', 'G' },
    { 'O', 'U' },
    { 'Q', 'C' },
    { 'W', 'I' },
    { 'R', 'L' },
    { 'X', 'P' },
    { 'Z', 'K' }
  };
  Enigma enigma({ {3,1,2}, {4,8,10}, 0, plugs }, library);

  std::string toScrumble = "IWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORSIWANTTOROTATEALLTHEROTATORS";
  std::cout << toScrumble << std::endl;
  std::string scrubled = enigma.scrumble(toScrumble);
  std::cout << scrubled << std::endl;

  Enigma decoder({ { 3,1,2 },{ 4,8,10 }, 0, plugs }, library);
  std::string back = decoder.scrumble(scrubled);
  std::cout << back << std::endl;
}