#include "GerenciadorGrafico.h"


GerenciadorGrafico::GerenciadorGrafico() : texturas()
{
  std::string filename ("");
  std::ifstream file("Gerenciadores/Textures.txt");
  while (file >> filename) {
    sf::Texture *texture = new sf::Texture();  
    if (!texture->loadFromFile("Texturas/"+filename))
    {
      std::cout << "Erro ao carregar a textura: " << filename << std::endl;
      return;
    }
    texturas.push_back(texture);
  }
}

GerenciadorGrafico::~GerenciadorGrafico()
{
  int i;
  for ( i = 0; i < texturas.size(); i++)
  {
    free(texturas[i]);
  }
  texturas.clear();
}

sf::Texture* GerenciadorGrafico::operator[] (int i) const 
{
  if(i >= 0 && i < texturas.size())
  {
    return(texturas[i]);
  }
  else
  {
    std::cout << "erro ao retornar textura em GG \n ";
    exit(0);
  }
}