#include "Personagem.h"

class Jogador : public Personagem
{
private:

public:
  Jogador(float x = 0, float y = 0, float w = 0, float h = 0, sf::Texture* t = NULL, Colisao c = Colisao(), int v = 0, Animacao a = Animacao());
  ~Jogador();
  virtual void executar(float dt);
};
