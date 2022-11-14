#include "GerenciadorEventos.h"
#include "../Principal.h"

namespace Gerenciadores
{

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

  int estado = IDLE;
  
  Jogador* j = this->p->getFase()->getJogador(1);
  while (this->p->getGerenciadorGrafico()->getWindow()->pollEvent(event))
  {

    if (event.type == sf::Event::Closed)
    {
      this->p->getGerenciadorGrafico()->getWindow()->close();
    }
    else if(p->getMenu()->getPausa())
    { 
      if (event.type == sf::Event::MouseButtonPressed)
      { 
        Menu* pMenu = p->getMenu();
      
        float xm = sf::Mouse::getPosition(*p->getGerenciadorGrafico()->getWindow()).x;
        float ym = sf::Mouse::getPosition(*p->getGerenciadorGrafico()->getWindow()).y;

        pMenu->mouseClick(sf::Vector2<float>(xm,ym));

      }
    }

    if (event.type == sf::Event::KeyPressed)
    {
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
      {
        p->getMenu()->setPausa(!(p->getMenu()->getPausa()));
      }
    }

    if (event.type == sf::Event::MouseButtonPressed)
    { 
      Menu* pMenu = p->getMenu();
    
      j->setXX0(sf::Mouse::getPosition(*this->p->getGerenciadorGrafico()->getWindow()).x);
      j->setYY0(sf::Mouse::getPosition(*this->p->getGerenciadorGrafico()->getWindow()).y);
    }
  }
  
  if(!p->getMenu()->getPausa())
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
      j->setXX0(j->getX()+10);
      j->setYY0(j->getY());
      estado = WALKR;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && j->getTproj() >= 2)
      {
        Projetil* p = new Projetil(j->getX()+j->getColisao().getWidth() - 10, j->getY()+j->getColisao().getHeight()/2, 1000, -20, 1);
        this->p->getFase()->getEntidades()->push(p);
        this->p->getFase()->getGCol()->incluir(p);
        j->setTproj();
      }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
    {
      j->setXX0(j->getX()-10);
      j->setYY0(j->getY());
      estado = WALKL;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && j->getTproj() >= 2)
      {
        Projetil* p = new Projetil(j->getX() - 50, j->getY()+j->getColisao().getHeight()/2, -1000, -20, 1);
        this->p->getFase()->getEntidades()->push(p);
        this->p->getFase()->getGCol()->incluir(p);
        j->setTproj();
      }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
      if(j->getVy() == 0)
      {
        j->setVy(-31);
        estado = JUMP;
      }
    }
    j->setEstado(estado);

    if(p->getFase()->getMltplyr())
    {
      j = this->p->getFase()->getJogador(2);
      estado = IDLE;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
      {
        j->setXX0(j->getX()+10);
        j->setYY0(j->getY());
        estado = WALKR;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && j->getTproj() >= 2)
        {
          Projetil* p = new Projetil(j->getX()+j->getColisao().getWidth(), j->getY()+j->getColisao().getHeight()/2, 1000, -20, 1);
          this->p->getFase()->getEntidades()->push(p);
          this->p->getFase()->getGCol()->incluir(p);
          j->setTproj();
        }
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
      {
        j->setXX0(j->getX()-10);
        j->setYY0(j->getY());
        estado = WALKL;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && j->getTproj() >= 2)
        {
          Projetil* p = new Projetil(j->getX() - 50, j->getY()+j->getColisao().getHeight()/2, -1000, -20, 1);
          this->p->getFase()->getEntidades()->push(p);
          this->p->getFase()->getGCol()->incluir(p);
          j->setTproj();
        }
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
      {
        if(j->getVy() == 0)
        {
          j->setVy(-31);
          estado = JUMP;
        }
      }
      
      j->setEstado(estado);
    }
  }
}

}
