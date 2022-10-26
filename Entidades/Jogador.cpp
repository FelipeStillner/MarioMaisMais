#include "Jogador.h"
#include "../Principal.h"

Jogador::Jogador(Principal* p, float x, float y, float w, float h, sf::Texture* t, Colisao c, int v, Animacao a): Personagem(x, y, w, h, t, c, v, a)
{
  if(p == NULL)
  {
    exit(0);
  }
  this->p = p;
}

Jogador::~Jogador()
{
}

void Jogador::executar(float dt)
{
  y0 = y;
  y += vy;
  vy += 2;
  anim.executar(dt);
}

void Jogador::setEstado(const int est)
{
  if(estado == est)
  {
    return;
  }

  switch (est)
  {
  case IDLE:
    if(estado == WALKR)
    {
      setTextura(p->gGraf.texturas[6]);
      setAnimacao(Animacao(sf::IntRect(0, 0 ,16, 32)));
    }
    else
    {
      setTextura(p->gGraf.texturas[6]);
      setAnimacao(Animacao(sf::IntRect(16, 0 ,-16, 32)));
    }
    break;
  
  case WALKR:
    setAnimacao(Animacao(sf::IntRect(0, 0, 16, 32), 0.25, "1232"));
    setTextura(p->gGraf.texturas[0]);
    break;

  case WALKL:
    setAnimacao(Animacao(sf::IntRect(48, 0, -16, 32), 0.25, "1232"));
    setTextura(p->gGraf.texturas[0]);
    break;
  
  case JUMP:
    setAnimacao(Animacao(sf::IntRect(0, 0, 16, 32), 2, "12"));
    setTextura(p->gGraf.texturas[7]);
    break;
  
  default:
    break;
  }
  estado = est;
}

const int Jogador::getEstado() const
{
  return estado;
}
