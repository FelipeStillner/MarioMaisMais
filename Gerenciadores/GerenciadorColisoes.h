#pragma once

#include "../Entidades/Personagens/Inimigo.h"
#include "../Entidades/Obstaculos/Obstaculo.h"
#include "../Entidades/Personagens/Jogador.h"
#include "../Entidades/Projetil.h"

namespace Fases
{
  class Fase;
}

using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;
using namespace Fases;


namespace Gerenciadores
{

class GerenciadorColisoes
{
private:
  Jogador* jog;
  Jogador* jog2;
  std::list<Projetil*> proj;
  std::list<Inimigo*> inim;
  std::list<Obstaculo*> obst;
public:
  GerenciadorColisoes();
  ~GerenciadorColisoes();
  void executar();
  void incluir(Jogador* j);
  void incluir(Projetil* p);
  void incluir(Inimigo* i);
  void incluir(Obstaculo* o);
};

}
