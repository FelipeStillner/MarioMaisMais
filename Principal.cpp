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
    Entidade *e = new Entidade(1, 1000, 1000, texture, Animacao(sf::IntRect(0, 0, 30, 30), 0.5, "12"));
    Entidade *ent = new Entidade(2, 0, 0, texture, Animacao(sf::IntRect(0, 0, 30, 30), 0.5, "12"));
    e->col = new Colisao(100, 100);
    ent->col = new Colisao(100, 100);

    while (window.isOpen())
    {
        window.clear();
        ent->imprimir(&window);
        e->imprimir(&window);
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
                e->x = sf::Mouse::getPosition(window).x;
                e->y = sf::Mouse::getPosition(window).y;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                ent->x += 5;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                ent->x -= 5;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                ent->y -= 5;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                ent->y += 5;
            }
        }
        e->executar(dt);
        if(colidindo(e, ent))
        {
            e->vy = 0;
        }
        if(e->y >= 1000)
        {
            e->vy = 0;
        }
    }
}
