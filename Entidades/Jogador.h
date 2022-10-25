#include "Personagem.h"

class Jogador : public Personagem
{
private:
  
public:
  Jogador(float x = 0, float y = 0, sf::Texture* t = NULL, Colisao c = Colisao(), int v = 0, Animacao a = Animacao());
  ~Jogador();
};
