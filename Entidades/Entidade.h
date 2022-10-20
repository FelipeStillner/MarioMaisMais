#pragma once

#include "../Ente.h"
#include "../ClassesAuxiliares/Colisao.h"

class Entidade : public Ente
{
protected:
  int x, y;
  int x0, y0;
  sf::Texture *text;
  Colisao col;
public:
  Entidade(float x = 0, float y = 0, sf::Texture* t = NULL, Colisao c = Colisao());
  virtual ~Entidade();
  virtual void executar(float dt) = 0;
  virtual void imprimir(sf::RenderWindow *rw) = 0;
  void setColisao(Colisao c);
  void setTextura(sf::Texture* t);
  void setX(int x);
  void setY(int y);
  const Colisao getColisao() const;
  const sf::Texture* getTextura() const;
  const int getX() const;
  const int getY() const;
  const int getX0() const;
  const int getY0() const;
};
