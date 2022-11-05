#pragma once

#include "Entidades/Entidade.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Afix.h"
#include "Ente.h"
//#include "Texto.h"

using std::string;
using std::vector;

class Menu : public Ente
{
private:
  vector<sf::IntRect*> letras;
  vector<string> strings;
  GerenciadorGrafico * gGraf;
public:
  Menu(GerenciadorGrafico * g = NULL);
  ~Menu();
  virtual void executar(float dt);
  virtual void imprimir(sf::RenderWindow* w);
  void setgGraf(GerenciadorGrafico * g);
  //void escreveTexto(string vTexto,int fIndex, int fX , int fY, int fSize);

};


