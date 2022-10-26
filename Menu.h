#pragma once
#include "Entidade/Entidade.h"

#include "Afix.h"
#include "Ente.h"
using std::string;
using std::list;
class Menu : public Ente
{
private:

  list<Texto*> lTexto;
  

public:
  Menu();
  ~Menu();
  virtual void executar(float dt);
  virtual void imprimir(sf::RenderWindow* w);
  void escreveTexto(string vTexto,int fIndex, int fX , int fY, int fSize);

};


