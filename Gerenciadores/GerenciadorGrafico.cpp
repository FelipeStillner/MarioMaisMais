#include "GerenciadorGrafico.h"

namespace Gerenciadores
{

GerenciadorGrafico::GerenciadorGrafico() : texturas()
{
  w = new sf::RenderWindow(sf::VideoMode(1280, 800), "SFML window");
  std::string filename ("");
  std::ifstream file("Gerenciadores/Textures.txt");
  while (file >> filename) {
    sf::Texture *texture = new sf::Texture();  
    if (!texture->loadFromFile("Texturas/" + filename))
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

sf::Texture* GerenciadorGrafico::operator[] (const int i) const 
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

sf::RenderWindow* GerenciadorGrafico::getWindow()
{
  return w;
}

}
