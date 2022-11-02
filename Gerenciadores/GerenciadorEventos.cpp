#include "GerenciadorEventos.h"
#include "../Principal.h"

GerenciadorEventos::GerenciadorEventos(Principal* p)
{
  this->p = p;
}

GerenciadorEventos::~GerenciadorEventos()
{
}

void GerenciadorEventos::executar()
{
  sf::Event event;
  while (this->p->getWindow()->pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
    {
      this->p->getWindow()->close();
    }
    if (event.type == sf::Event::MouseButtonPressed)
    {
      this->p->getFase()->getEntidades()->getJogador()->setXX0(sf::Mouse::getPosition(*this->p->getWindow()).x);
      this->p->getFase()->getEntidades()->getJogador()->setYY0(sf::Mouse::getPosition(*this->p->getWindow()).y);
    }
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    Jogador* p = this->p->getFase()->getEntidades()->getJogador();
    p->setXX0(p->getX()+10);
    p->setYY0(p->getY());
    p->setEstado(WALKR);
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    Jogador* p = this->p->getFase()->getEntidades()->getJogador();
    p->setXX0(p->getX()-10);
    p->setYY0(p->getY());
    p->setEstado(WALKL);
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    Jogador* p = this->p->getFase()->getEntidades()->getJogador();
    if(p->getVy() == 0)
    {
        p->setVy(-31);
        p->setXX0(p->getX());
        p->setEstado(JUMP);
    }
  }
  else 
  {
      p->getFase()->getEntidades()->getJogador()->setEstado(IDLE);   
  }
}
