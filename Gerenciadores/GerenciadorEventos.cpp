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
  int estado = IDLE;
  sf::Event event;
  Jogador* j = this->p->getFase()->getJogador();
  while (this->p->getGerenciadorGrafico()->getWindow()->pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
    {
      this->p->getGerenciadorGrafico()->getWindow()->close();
    }
    if (event.type == sf::Event::MouseButtonPressed)
    {
      j->setXX0(sf::Mouse::getPosition(*this->p->getGerenciadorGrafico()->getWindow()).x);
      j->setYY0(sf::Mouse::getPosition(*this->p->getGerenciadorGrafico()->getWindow()).y);
    }
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    j->setXX0(j->getX()+10);
    j->setYY0(j->getY());
    estado = WALKR;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    j->setXX0(j->getX()-10);
    j->setYY0(j->getY());
    estado = WALKL;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    if(j->getVy() == 0)
    {
      j->setVy(-31);
      j->setXX0(j->getX());
      estado = JUMP;
    }
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
  {
    Projetil* p = new Projetil(this->p->getGerenciadorGrafico(),j->getX()+j->getColisao().getWidth(), j->getY()+j->getColisao().getHeight()/2, 80, 80, Colisao(10,10,60,60), 200, 0, 1);
    this->p->getFase()->getEntidades()->push(p);
  }
  j->setEstado(estado);
}
