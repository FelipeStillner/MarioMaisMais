#pragma once

#include "../Entidades/Jogador.h"

class Principal;

class GerenciadorEventos
{
private:
  Principal* p;
public:
  GerenciadorEventos();
  ~GerenciadorEventos();
  void executar();
};
