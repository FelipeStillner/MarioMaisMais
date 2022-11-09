#include "Jogador.h"
#include "../Principal.h"

Jogador::Jogador(float x, float y, float w, float h, int t, Colisao c, int v, Animacao a): Personagem(x, y, w, h, t, c, v, a)
{

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
  
  switch (estado)
  {
  case IDLE:
    if(estado == WALKR)
    {
      /*t = (*(p->getGerenciadorGrafico()))[6];*/
      setTextura(6);
    }
    else
    {
      /*t = (*(p->getGerenciadorGrafico()))[6];*/
      setTextura(6);
    }
    break;
  
  case WALKR:
    /*t = (*(p->getGerenciadorGrafico()))[0];*/
      setTextura(0);
    break;

  case WALKL:
      setTextura(0);
    break;
  
  case JUMP:
      setTextura(7);
    break;
  
  default:
    break;
  }
  sf::Texture* t = text;
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
