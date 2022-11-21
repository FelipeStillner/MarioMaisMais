#pragma once

#include "../Entidade.h"
#include "../Personagens/Personagem.h"

namespace Entidades
{

namespace Obstaculos
{

class Obstaculo : public Entidade
{
protected:
public:
  Obstaculo(float x = 0, float y = 0, float w = 0, float h = 0, Colisao c = Colisao());
  virtual ~Obstaculo();
  virtual void executar(const float dt) = 0;
  virtual void imprimir() = 0;
  virtual int const getTipo() const = 0;
  virtual void obstacular(Personagem* e, int dir) = 0;
};

}

}

using namespace Obstaculos;
