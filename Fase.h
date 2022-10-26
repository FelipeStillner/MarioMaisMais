#pragma once

#include "Afix.h"
#include "Ente.h"
#include "ClassesAuxiliares/ListaEntidades.h"
#include "Gerenciadores/GerenciadorColisoes.h"

class Fase : public Ente
{
private:
  GerenciadorColisoes gCol;
  ListaEntidades entidades;
  sf::Texture* background;
public:
  Fase();
  virtual ~Fase();
  virtual void executar(float dt);
  void gerenciarColisoes();
};
