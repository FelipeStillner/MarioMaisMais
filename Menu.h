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
  bool pausado;
  
public:
  Menu(int k = 0);

  ~Menu();
  void executar(float dt);
  void imprimir   ();
  void setPausa(bool p);
  const bool getPausa() const ;
  
  //void escreveTexto(string vTexto,int fIndex, int fX , int fY, int fSize);

};


