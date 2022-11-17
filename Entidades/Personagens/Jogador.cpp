#include "Jogador.h"

Jogador::Jogador(float x, float y, int v): Personagem(x, y, 160, 320, v, Colisao(10, 10, 140, 300), Animacao(sf::IntRect(0, 0, 16, 32), 0.25, "1"))
{
  tProj = 0;
}

Jogador::~Jogador()
{
}

void Jogador::executar(float dt)
{
  y0 = y;
  y = y + vy*dt;
  vy += Grav;
  anim.executar(dt);
  tProj += dt;
  if(tProj >= 2)
  {
    tProj = 2;
  }
}

void Jogador::imprimir()
{
  sf::Texture* t = NULL;
  switch (estado)
  {
  case IDLE:
    if(estado == WALKR)
    {
      t = (*gG)[6];
    }
    else
    {
      t = (*gG)[6];
    }
    break;
  
  case WALKR:
      t = (*gG)[0];
    break;

  case WALKL:
      t = (*gG)[0];
    break;
  
  case JUMP:
      t = (*gG)[7];
    break;
  
  default:
    break;
  }
  sf::RectangleShape r;
  r.setTexture(t);
  r.setTextureRect(anim.rect);
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  gG->getWindow()->draw(r);
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
      setAnimacao(Animacao(sf::IntRect(0, 0 ,16, 32)));
    }
    else
    {
      setAnimacao(Animacao(sf::IntRect(16, 0 ,-16, 32)));
    }
    break;
  
  case WALKR:
    setAnimacao(Animacao(sf::IntRect(0, 0, 16, 32), 0.25, "1232"));
    break;

  case WALKL:
    setAnimacao(Animacao(sf::IntRect(48, 0, -16, 32), 0.25, "1232"));
    break;
  
  case JUMP:
    setAnimacao(Animacao(sf::IntRect(0, 0, 16, 32), 0.3, "12"));
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

int Jogador::getTipo()
{
  return  PLAYER;
}

float Jogador::getTproj()
{
  return tProj;
}

void Jogador::setTproj(float t)
{
  tProj = t;
}
