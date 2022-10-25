#include "Personagem.h"

class Inimigo : public Personagem
{
private:
  /* data */
public:
  Inimigo(float x = 0, float y = 0, sf::Texture* t = NULL, Colisao c = Colisao(), int v = 0, Animacao a = Animacao());
  ~Inimigo();
  virtual void atacar() {};
};
