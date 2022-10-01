#include "Principal.h"

Principal::Principal()
{
  executar();
}

Principal::~Principal()
{
}

void Principal::executar()
{
    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    sf::Texture *texture = new sf::Texture();
    if (!texture->loadFromFile("a.png"))
        return;
    Entidade e(1, 2.1, 3.4, texture, Animacao(sf::IntRect(0, 0, 30, 30), 1.0, "1234567"));

    while (window.isOpen())
    {
        sf::Time a = clock.getElapsedTime();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        e.executar(a.asMilliseconds());
        e.imprimir(&window);
        window.display();
        clock.restart();
    }
}
