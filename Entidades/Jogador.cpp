#include "Jogador.h"
#include "../Principal.h"

Jogador::Jogador(Principal* p, GerenciadorGrafico* g, float x, float y, float w, float h, Colisao c, int v, Animacao a): Personagem(g, x, y, w, h, c, v, a)
{
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

void Jogador::imprimir()
{
  sf::Texture* t;
  switch (estado)
  {
  case IDLE:
    if(estado == WALKR)
    {
      t = (*(p->getGerenciadorGrafico()))[6];
    }
    else
    {
      t = (*(p->getGerenciadorGrafico()))[6];
    }
    break;
  
  case WALKR:
    t = (*(p->getGerenciadorGrafico()))[0];
    break;

  case WALKL:
    t = (*(p->getGerenciadorGrafico()))[0];
    break;
  
  case JUMP:
    t = (*(p->getGerenciadorGrafico()))[7];
    break;
  
  default:
    break;
  }
  sf::RectangleShape r;
  r.setTexture(t);
  r.setTextureRect(anim.rect);
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  gGraf->getWindow()->draw(r);
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
