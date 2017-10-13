#pragma once
#include <string>
#include "Enigma.h"

class SetupReader
{
public:
  static Enigma::Setup readFromPath(const std::string& path);
  static std::string readWholeInput(const std::string& path);
};