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
public:
  ListaEntidades entidades;
  Jogador* jog;
  bool isPlaying;
public:
  Fase(Principal *p);
  virtual ~Fase();
  virtual void executar(float dt);
  virtual void imprimir(sf::RenderWindow *w);
  void gerenciarColisoes();
};
