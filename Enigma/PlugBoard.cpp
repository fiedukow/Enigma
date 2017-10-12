#include "PlugBoard.h"
#include <cassert>
#include <boost/optional.hpp>

PlugBoard::PlugBoard(const std::map<char, char>& plugs) {
  for (auto plug : plugs) {
    this->plugs.left.insert(std::pair<char, char>(plug.first, plug.second));
  }
}

void PlugBoard::plug(char c1, char c2) {
  assert(c1 != c2);
  plugs.left.insert(std::pair<char, char>(c1, c2));
}

void PlugBoard::unplug(char c) {
  auto leftPlug = plugs.left.find(c);
  if (leftPlug != plugs.left.end()) {
    plugs.left.erase(leftPlug);
    return;
  }

  auto rightPlug = plugs.right.find(c);
  if (rightPlug != plugs.right.end()) {
    plugs.right.erase(rightPlug);
    return;
  }
}

bool PlugBoard::isPlugged(char c) const {
  return (plugs.left.find(c) != plugs.left.end() ||
    plugs.right.find(c) != plugs.right.end());
}

boost::optional<char> PlugBoard::pluggedTo(char c) const {
  auto leftPlug = plugs.left.find(c);
  if (leftPlug != plugs.left.end()) {
    return leftPlug->second;
  }

  auto rightPlug = plugs.right.find(c);
  if (rightPlug != plugs.right.end()) {
    return rightPlug->second;
  }

  return boost::optional<char>();
}

char PlugBoard::scrumble(char letter) const {
  auto pluged = pluggedTo(letter);
  if (pluged)
    return *pluged;
  return letter;
}
