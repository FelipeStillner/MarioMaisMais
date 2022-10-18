#pragma once

#include "Afix.h"
#include "Ente.h"

class Menu : public Ente
{
private:
  
public:
  Menu();
  ~Menu();
  virtual void executar(float dt);
  virtual void imprimir(sf::RenderWindow* w);
};

Menu::Menu() : Ente()
{
}

Menu::~Menu()
{
}

void executar(float dt)
{

}

void imprimir(sf::RenderWindow* w)
{

}
