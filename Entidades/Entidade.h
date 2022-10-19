#pragma once

#include "../Ente.h"
#include "../ClassesAuxiliares/Animacao.h"
#include "../ClassesAuxiliares/Colisao.h"

class Entidade : public Ente
{
protected:
  int x, y;
  sf::Texture *text;
  Colisao col;
public:
  Entidade(float x = 0, float y = 0, sf::Texture* t = NULL, Colisao c = Colisao());
  ~Entidade();
  virtual void executar(float dt);
  virtual void imprimir(sf::RenderWindow *rw);
  void setColisao(Colisao c);
  void setTextura(sf::Texture* t);
  void setX(int x);
  void setY(int y);
  const Colisao getColisao() const;
  const sf::Texture* getTextura() const;
  const int getX() const;
  const int getY() const;
};
