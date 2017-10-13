#include "SetupReader.h"
#include <fstream>

Enigma::Setup SetupReader::readFromPath(const std::string& path) {
  std::ifstream input(path, std::ifstream::in);
  if (input.bad())
    throw new std::runtime_error("File " + path + " is not readable");
  Enigma::Setup result;

  input >> result.rotors[0] >> result.rotors[1] >> result.rotors[2];
  input >> result.reflectorId;
  input >> result.positions[0] >> result.positions[1] >> result.positions[2];

  int noPairs;
  input >> noPairs;

  std::map<char, char> plugs;
  for (int i = 0; i < noPairs; ++i) {
    std::string pair;
    input >> pair;
    plugs.insert(std::pair<char, char>(pair[0], pair[1]));
  }

  result.plugs = plugs;
  input.close();

  return result;
}

std::string SetupReader::readWholeInput(const std::string & path)
{
  std::ifstream input(path);
  std::string result;

  input.seekg(0, std::ios::end);
  result.reserve(input.tellg());
  input.seekg(0, std::ios::beg);

  result.assign((std::istreambuf_iterator<char>(input)),
    std::istreambuf_iterator<char>());

  return result;
}
