#pragma once

#include "../Ente.h"
#include "../ClassesAuxiliares/Colisao.h"

using namespace ClassesAuxiliares;
using namespace Entidades;

namespace Entidades
{

class Entidade : public Ente
{
protected:
  float x, y;
  float w, h;
  float x0, y0;
  int vy;
  bool ativo;
  Colisao col;
public:
  Entidade(float x = 0, float y = 0, float w = 0, float h = 0, Colisao c = Colisao());
  virtual ~Entidade();
  virtual void executar(float dt) = 0;
  virtual void imprimir() = 0;
  void setX(float x);
  void setY(float y);
  void setXX0(float x);
  void setYY0(float y);
  void setVy(float v);
  Colisao getColisao();
  const float getX() const;
  const float getY() const;
  const float getX0() const;
  const float getY0() const;
  const float getVy() const;
  void setAtivo(bool a = true);
  const bool getAtivo() const;
  virtual int getTipo() = 0;
};

}
