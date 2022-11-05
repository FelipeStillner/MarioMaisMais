#pragma once

#include "Entidades/Entidade.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Afix.h"
#include "Ente.h"
#include "Texto.h"

using std::string;
using std::vector;

class Menu : public Ente
{
private:
  vector<sf::IntRect*> letras;
  vector<string> strings;
  GerenciadorGrafico gText;
public:
  Menu(/*GerenciadorGrafico * gT*/);
  void setgT(GerenciadorGrafico * gT);
  ~Menu();
  virtual void executar(float dt);
  virtual void imprimir(sf::RenderWindow* w);
  //void escreveTexto(string vTexto,int fIndex, int fX , int fY, int fSize);

};


