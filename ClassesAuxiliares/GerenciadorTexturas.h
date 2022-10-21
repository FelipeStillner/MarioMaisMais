#pragma once

#include "../Afix.h"
#include <fstream>

class GerenciadorTexturas
{
public:
  std::vector<sf::Texture*> lista;
public:
  GerenciadorTexturas();
  ~GerenciadorTexturas();
};
