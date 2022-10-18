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
  Animacao();
  Animacao(sf::IntRect r, float tAnim, std::string seq);
  ~Animacao();
  void executar(float dt);
};
