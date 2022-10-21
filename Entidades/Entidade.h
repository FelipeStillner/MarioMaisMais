#pragma once

#include "../Ente.h"
#include "../ClassesAuxiliares/Colisao.h"

class Entidade : public Ente
{
protected:
  float x, y;
  float x0, y0;
  sf::Texture *text;
  Colisao col;
public:
  Entidade(float x = 0, float y = 0, sf::Texture* t = NULL, Colisao c = Colisao());
  virtual ~Entidade();
  virtual void executar(float dt) = 0;
  virtual void imprimir(sf::RenderWindow *rw) = 0;
  void setColisao(Colisao c);
  void setTextura(sf::Texture* t);
  void setX(float x);
  void setY(float y);
  const Colisao getColisao() const;
  const sf::Texture* getTextura() const;
  const float getX() const;
  const float getY() const;
  const float getX0() const;
  const float getY0() const;
};
