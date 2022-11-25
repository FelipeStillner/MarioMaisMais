#pragma once

#include "../Ente.h"
#include "../ClassesAuxiliares/Colisao.h"

using namespace ClassesAuxiliares;
using namespace Entidades;

namespace Entidades
{

class Entidade : public Ente, public Colisao
{
protected:
  float x, y;
  float w, h;
  float x0, y0;
  float vy;
  bool ativo;
public:
  Entidade(float x = 0, float y = 0, float w = 0, float h = 0, Colisao c = Colisao());
  virtual ~Entidade();
  virtual void executar(const float dt) = 0;
  virtual void imprimir() = 0;
  virtual const int getTipo() const = 0;
  const Colisao getColisao() const;
  const float getX() const;
  const float getY() const;
  const float getX0() const;
  const float getY0() const;
  const float getVy() const;
  const bool getAtivo() const;
  void setX(const float x);
  void setY(const float y);
  void setXX0(const float x);
  void setYY0(const float y);
  void setVy(const float v);
  void setAtivo(const bool a = true);
};

}
