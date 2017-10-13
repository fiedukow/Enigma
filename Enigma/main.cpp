#include <iostream>
#include <iomanip>
#include <map>
#include "ComponentsLibrary.h"
#include "Enigma.h"
#include "SetupReader.h"

void printMessage(const std::string& message) {
  int i = 0;
  while (i * 8 < message.size()) {
    std::cout << "==  ";
    for (int l = 0; l < 4 && i * 8 < message.size(); ++i, ++l) {
      std::cout << message.substr(i * 8, 8) << " ";
    }
    if (i * 8 >= message.size()) {
      int lettersMissing = (32 - (message.size() % 32)) % 32;
      int spacesMissing = (4 - ((message.size() % 32) + 8 - 1) / 8) % 4;
      std::cout << std::setw(lettersMissing + spacesMissing) << " ";
    }
    std::cout << " ==" << std::endl;
  }
}

int main(int argc, char** argv) {
  if (argc != 3) {
    std::cout << "Usage: " << argv[0] << " SETUP_FILE CODE_FILE" << std::endl;
    return EXIT_FAILURE;
  }

  Enigma::Setup setup = SetupReader::readFromPath(argv[1]);
  std::string message = SetupReader::readWholeInput(argv[2]);

  std::cout << "===========================================" << std::endl;
  std::cout << "========= STARTING ENIGMA MACHINE =========" << std::endl;
  std::cout << "===========================================" << std::endl;
  std::cout << "=========     SETUP FOR TODAY     =========" << std::endl;
  std::cout << "== ROTORS: " << setup.rotors[0] << " " << setup.rotors[1] << " " << setup.rotors[2] << "                         ==" << std::endl;
  std::cout << "== POSITIONS: " << std::setw(2) << setup.positions[0] << std::setw(0) << " "
                                << std::setw(2) << setup.positions[1] << std::setw(0) << " "
                                << std::setw(2) << setup.positions[2] << std::setw(0) << " "
                                << "                  ==" << std::endl;
  std::cout << "== REFLECTOR: " << setup.reflectorId << "                          ==" << std::endl;
  std::cout << "== PLUGS: ";
  for (auto plug : setup.plugs) {
    std::cout << plug.first << plug.second << " ";
  }
  std::cout << " ==" << std::endl;
  std::cout << "===========================================" << std::endl;

  std::cout << "=========    MESSAGE TO CIPHER    =========" << std::endl;
  printMessage(message);
  std::cout << "===========================================" << std::endl;

  ComponentsLibrary library;
  Enigma enigma(setup, library);
  std::string scrumbled = enigma.scrumble(message);  

  std::cout << "=========        CIPHERTEXT       =========" << std::endl;
  printMessage(scrumbled);
  std::cout << "===========================================" << std::endl;

  Enigma decoder(setup, library);
  std::string readback = decoder.scrumble(scrumbled);

  std::cout << "=========         READBACK        =========" << std::endl;
  printMessage(readback);
  std::cout << "===========================================" << std::endl;
  
  return EXIT_SUCCESS;
}