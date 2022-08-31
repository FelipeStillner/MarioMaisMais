#include "Principal.h"

Principal::Principal(/* args */)
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
    sf::Texture texture;
    if (!texture.loadFromFile("a.png"))
        return;
    sf::Sprite sprite(texture, sf::IntRect(0, 75, 21, 40));
    sprite.move(sf::Vector2f(100, 100));

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
        sprite.move(sf::Vector2f(100, 100));
        // Draw the sprite
        window.draw(sprite);
        // Update the window
        window.display();
    }
}
