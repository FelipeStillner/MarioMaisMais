#pragma once

#include "../Afix.h"
#include <fstream>

class GerenciadorGrafico
{
public:
  std::vector<sf::Texture*> texturas;
public:
  GerenciadorGrafico();
  ~GerenciadorGrafico();
};
