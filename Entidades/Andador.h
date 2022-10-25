#include "Inimigo.h"

class Andador : public Inimigo
{
private:
public:
  Andador(float x = 0, float y = 0, sf::Texture* t = NULL, Colisao c = Colisao(), int v = 0 ,Animacao a = Animacao());
  ~Andador();
  void executar(float dt);
};


