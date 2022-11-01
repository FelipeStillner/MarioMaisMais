#pragma once

#include "../Entidades/Inimigo.h"
#include "../Entidades/Obstaculo.h"
#include "../Entidades/Jogador.h"
#include "../Entidades/Projetil.h"

class Fase;

class GerenciadorColisoes
{
private:
  Fase* f;
public:
  GerenciadorColisoes(Fase* f);
  ~GerenciadorColisoes();
  void executar();
};
