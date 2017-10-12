#pragma once
#include <boost/bimap.hpp>
#include <boost/optional.hpp>
#include <map>

class PlugBoard
{
private:
  boost::bimap<char, char> plugs;

public:
  PlugBoard(const std::map<char, char>& plugs);

  void plug(char c1, char c2);
  void unplug(char c);

  bool isPlugged(char c) const;
  boost::optional<char> pluggedTo(char c) const;

  char scrumble(char letter) const;
};