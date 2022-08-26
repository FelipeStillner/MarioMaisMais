#include "Principal.h"

Principal::Principal()
{
}

Principal::~Principal()
{
}

void Principal::exec()
{
  sf::RenderWindow window(sf::VideoMode(300, 300), "NOME");
  
  sf::Clock clock;

  while (window.isOpen())
  {
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

    window.clear(sf::Color::Blue);
    window.display();
  }
}
