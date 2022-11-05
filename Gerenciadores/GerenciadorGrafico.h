#pragma once

#include "../Afix.h"
#include <fstream>
class GerenciadorGrafico
{
private:
  std::vector<sf::Texture*> texturas;
  sf::RenderWindow* w;
public:
  GerenciadorGrafico();
  ~GerenciadorGrafico();
  sf::Texture* operator[] (const int i) const ;
  void imprimir();
  sf::RenderWindow* getWindow();
};
