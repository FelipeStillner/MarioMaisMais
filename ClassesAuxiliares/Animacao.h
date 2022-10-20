#pragma once

#include "../Afix.h"

class Animacao
{
public:
  sf::IntRect rect;
private: 
  float tTotal;
  float tAnim;
  std::string seq;
  int at;
public:
  Animacao(sf::IntRect r = sf::IntRect(), float tAnim = 0, std::string seq = std::string());
  ~Animacao();
  void executar(float dt);
};
