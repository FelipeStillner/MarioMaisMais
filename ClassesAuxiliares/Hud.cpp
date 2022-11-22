#include "Hud.h"
#include "../Fases/Fase.h"
#include "Botao.h"

Hud::Hud(Fase* f)
{
  this->f = f;
}

Hud::~Hud()
{
}

void Hud::imprimir()
{
  int x = -gG->getWindow()->getView().getCenter().x - gG->getWindow()->getSize().x/2 + 100,
    y = -gG->getWindow()->getView().getCenter().y - gG->getWindow()->getSize().y/2;
  sf::RectangleShape r;
  r.setTexture((*gG)[16]);
  r.setOrigin(x, 0);
  r.setSize(sf::Vector2f(80, 80));
  for (int i = 0; i < f->getJogador(1)->getVida(); i++)
  {
    r.setOrigin(x, 0);
    gG->getWindow()->draw(r);
    x += 100;
  }

  Botao b1(sf::Vector2f(-400, -200),std::to_string(f->getJogador(1)->getPont()));
  b1.imprimir();
  
  if (f->getMltplyr())
  {
    r.setTexture((*gG)[17]);
    x = -gG->getWindow()->getView().getCenter().x - gG->getWindow()->getSize().x/2 + 100;
    r.setSize(sf::Vector2f(80, 80));
    for (int i = 0; i < f->getJogador(2)->getVida(); i++)
    {
      r.setOrigin(x, -100);
      gG->getWindow()->draw(r);
      x += 100;
    }

    Botao b2(sf::Vector2f(-400, -100),std::to_string(f->getJogador(2)->getPont()));
    b2.imprimir();
  }

}

void Hud::executar(float dt)
{
}