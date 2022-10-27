#pragma once

#include "../Afix.h"
#include <fstream>
class GerenciadorGrafico
{
private:
  std::vector<sf::Texture*> texturas;
public:
  GerenciadorGrafico();
  ~GerenciadorGrafico();
  sf::Texture* operator[] (int i) const ;
};
