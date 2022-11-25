#pragma once 

#include "Inimigo.h"
#include "../../Fases/Fase.h"

namespace Entidades
{

namespace Personagens
{

class Lancador : public Inimigo
{
private:
  Fase* f;
  float tLan;
public:
  Lancador(Fase* f, float x = 0, float y = 0, int v = 0);
  ~Lancador();
  void executar(const float dt);
  void imprimir();
  const int getTipo() const;
  void danar();
  const int getPontuacao() const;
};

}

}
