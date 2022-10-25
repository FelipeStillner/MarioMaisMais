#include "Animacao.h"

Animacao::Animacao(sf::IntRect r, float tA, std::string s): seq(s)
{
  rect = r;
  tAnim = tA;
  tTotal = 0;
  at = 0;
}

Animacao::~Animacao()
{
}

void Animacao::executar(float dt)
{
  if (seq == std::string())
  {
    return;
  }
  tTotal += dt;
  if (tTotal >= tAnim)
  {
    int ant = at;
    at++;
    at %= seq.size();
    rect.left += (seq[at] - seq[ant]) * rect.width;
    tTotal -= tAnim;
  }
}


