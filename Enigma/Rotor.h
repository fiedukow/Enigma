#pragma once
#include <string>
#include <boost/optional.hpp>

/*
 * State full class describing Roter and it's current position
 */
class Rotor
{
private:
  static const std::string ALPHABET;
  const std::string baseCombinatation;
  const std::string baseReversedCombinatation;
  const boost::optional<Rotor*> toKick;

  std::string currentCombination;
  std::string currentReversedCombinatation;
  int position;

public:
  Rotor(const std::string& baseCombinatation, int position = 0, boost::optional<Rotor*> toKick = boost::optional<Rotor*>());
  
  void setTo(int position);
  void rotate();
  char scrumble(char c);
  char unscrumble(char c);

private:
  static std::string reverseCombination(const std::string& combination);
};
