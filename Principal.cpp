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
    const float FPS = 60.0;
    bool redraw = true;
    float dt ;
    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(1600, 1200), "SFML window");
    sf::Event event;
    window.setFramerateLimit(FPS);

    sf::Texture *texture = new sf::Texture();
    if (!texture->loadFromFile("a.png"))
        return;
    Entidade e(1, 2.1, 3.4, texture, Animacao(sf::IntRect(0, 0, 30, 30), 0.5, "12"));

    while (window.isOpen())
    {
        window.clear();
        e.imprimir(&window);
        dt = clock.getElapsedTime().asSeconds();  
        if (!(dt >= 1.0f / FPS))
        {
                sf::sleep(sf::seconds((1.0f / FPS) - dt));
                dt = 1.0f / FPS;
        }
        else{std::cout << "FPS\n";}
        clock.restart();
        window.display();

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                e.x = sf::Mouse::getPosition(window).x;
                e.y = sf::Mouse::getPosition(window).y;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                e.x += 5;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                e.x -= 5;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                e.y -= 5;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                e.y += 5;
            }
        }
        e.executar(dt);
    }
}
