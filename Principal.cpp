#include "Principal.h"

Principal::Principal()
{
}

Principal::~Principal()
{
}

void Principal::exec()
{
  sf::RenderWindow window(sf::VideoMode(1000, 1000), "NOME");
  sf::Texture t;// png com todos as imagens 
  t.loadFromFile("Textures/playerTexture.png");

  Animation a(sf::IntRect(0, 80, 29, 27), "0121", 0.2f, 0);
  
  float deltaTime;
  sf::Clock clock;

  while (window.isOpen())
  {
    deltaTime = clock.restart().asSeconds();
    sf::Event evnt;

    while (window.pollEvent(evnt))
    {
      switch (evnt.type)
      {
      case sf::Event::Closed:
        window.close();
        break;
      
      default:
        break;
      }
    }

    a.update(deltaTime);

    window.clear();

    window.draw(sf::Sprite(t, a.uvRect));

    window.display();
  }
}
