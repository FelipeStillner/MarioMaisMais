#pragma once



//objeto estado!!!!!!

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
  //vector<sf::IntRect*> boxes;
  int estado;
  bool pausado;
  
public:
  Menu(int k = 0);

  ~Menu();
  virtual void executar(float dt=0);
  void imprimir();
  void setPausa(bool p);
  const bool getPausa() const ;
  void setEstado(int e = -1);
  const int getEstado() const;
  void mouseClick(sf::Vector2<float> vMouse =sf::Vector2<float>());
  
  
  static void escreveTexto(string vTexto,int fX = 0 , float fY = 0, float len= 8.0);
  static void inicializaLetras();
  static void destroiLetras();
};


