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
protected:
  static vector<sf::IntRect*> * letras;
  vector<string> strings;
  bool pausado;
  
public:
  Menu(int k = 0);

  ~Menu();
  void executar(float dt);
  void imprimir   ();
  void setPausa(bool p);
  const bool getPausa() const ;
  
  static void escreveTexto(string vTexto,int fX = 0 , float fY = 0, float len= 8.0);
  static void inicializaLetras();
  static void destroiLetras();
};


