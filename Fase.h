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
  bool jogando;
public:
  Fase(Principal *p);
  virtual ~Fase();
  virtual void executar(float dt);
  virtual void imprimir(sf::RenderWindow *w);
  void gerenciarColisoes();
  ListaEntidades* getEntidades();
  bool getJogando();
  void setJogando(bool n);
  Jogador* getJogador();
  void setJogador(Jogador* jog);
};
