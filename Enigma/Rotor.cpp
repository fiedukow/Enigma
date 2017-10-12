#include "Rotor.h"
#include <vector>
#include <algorithm>
#include <boost/optional.hpp>

const std::string Rotor::ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

Rotor::Rotor(const std::string& baseCombinatation, int position, boost::optional<Rotor*> toKick)
  : baseCombinatation(baseCombinatation),
    baseReversedCombinatation(reverseCombination(baseCombinatation)),
    toKick(toKick),
    currentCombination(baseCombinatation),
    currentReversedCombinatation(baseReversedCombinatation)
{
      setTo(position);
}

void Rotor::setTo(int position) {
  this->position = position;
  currentCombination = baseCombinatation;
  std::rotate(currentCombination.begin(), currentCombination.begin() + position, currentCombination.end());
  currentReversedCombinatation = reverseCombination(currentCombination);
}

void Rotor::rotate() {
  position = (position + 1) % ('[' - 'A');
  std::rotate(currentCombination.begin(), currentCombination.begin() + 1, currentCombination.end());
  currentReversedCombinatation = reverseCombination(currentCombination);
  if (position == 0 && toKick)
    (*toKick)->rotate();
}

char Rotor::scrumble(char c) {
  return currentCombination[c - 'A'];
}

char Rotor::unscrumble(char c) {
  return currentReversedCombinatation[c - 'A'];
}

std::string Rotor::reverseCombination(const std::string & combination) {  
  // pack roter coding with base id
  std::vector<std::pair<char, int>> indices;
  for (size_t i = 0; i < combination.size(); ++i) {
    indices.push_back({ combination[i], i });
  }

  // sort by char
  std::sort(indices.begin(), indices.end(), [](auto left, auto right) { return left.first < right.first; });

  // scruble APLHABET acordingly
  std::string result;
  for (auto id : indices) {
    result.push_back(ALPHABET[id.second]);
  }

  return result;
}
