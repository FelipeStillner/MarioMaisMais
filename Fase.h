#pragma once

#include "Afix.h"
#include "Ente.h"
#include "ClassesAuxiliares/ListaEntidades.h"
#include "Gerenciadores/GerenciadorColisoes.h"
#include "Entidades/Jogador.h"

class Fase : public Ente
{
protected:
  GerenciadorColisoes gCol;
  ListaEntidades entidades;
  Jogador* jog;
  sf::Texture* background;
  bool isPlaying;
  Principal* prin;
public:
  Fase(Principal *p);
  virtual ~Fase();
  virtual void executar(float dt);
  virtual void imprimir(sf::RenderWindow *w);
  void gerenciarColisoes();
};
