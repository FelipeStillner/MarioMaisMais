#pragma once

#include "Afix.h"
#include "Ente.h"
#include "ClassesAuxiliares/ListaEntidades.h"
#include "Gerenciadores/GerenciadorColisoes.h"

class Jogador;
class Principal;

class Fase : public Ente
{
protected:
  GerenciadorColisoes gCol;
  sf::Texture* background;
  Principal* prin;
  ListaEntidades entidades;
  Jogador* jog;
  Jogador* jog2;
  bool jogando;
  bool mltply;
public:
  Fase(Principal *p);
  virtual ~Fase();
  virtual void executar(float dt);
  virtual void imprimir();
  void gerenciarColisoes();
  ListaEntidades* getEntidades();
  bool getJogando();
  void setJogando(bool n);
  Jogador* getJogador(int i = 1);
  void setJogador(Jogador* j,int i = 1);
  void setMltplyr(bool m = false);
  const bool getMltplyr() const ;
};
