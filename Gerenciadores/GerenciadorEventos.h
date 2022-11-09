#pragma once

#include "../Entidades/Jogador.h"

class Principal;

namespace Gerenciadores
{

class GerenciadorEventos
{
private:
  Principal* p;
public:
  GerenciadorEventos(Principal* p);
  ~GerenciadorEventos();
  void executar();
};

}
