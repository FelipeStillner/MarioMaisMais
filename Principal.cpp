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
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    // Load a sprite to display
    sf::Texture *texture = new sf::Texture();
    if (!texture->loadFromFile("a.png"))
        return;
    Entidade e(1, 2.1, 3.4, texture ,Animacao(sf::IntRect(1, 1, 100, 100)));

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Draw the sprite
        e.imprimir(&window);
        // Update the window
        window.display();
    }
}
