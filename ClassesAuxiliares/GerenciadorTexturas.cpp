#include "GerenciadorTexturas.h"


GerenciadorTexturas::GerenciadorTexturas() : lista()
{
  std::string filename ("");
  std::ifstream file("ClassesAuxiliares/Textures.txt");
  while (file >> filename) {
    sf::Texture *texture = new sf::Texture();  
    if (!texture->loadFromFile("Texturas/"+filename))
    {
      std::cout << "Erro ao carregar a textura: " << filename << std::endl;
      return;
    }
    lista.push_back(texture);
  }
}

GerenciadorTexturas::~GerenciadorTexturas()
{
  int i;
  for ( i = 0; i < lista.size(); i++)
  {
    free(lista[i]);
  }
  lista.clear();
}

