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
    if (!texture->loadFromFile("Sprites/a.png"))
        return;
    Personagem *e = new Personagem(1000.0, 1000.0, texture, Colisao(10, 10), 1,Animacao(sf::IntRect(0, 0, 30, 30), 0.5, "12"));
    Personagem *ent = new Personagem(2, 0, texture, Colisao(10, 10), 1, Animacao(sf::IntRect(0, 0, 30, 30), 0.5, "12"));
    ListaEntes l;
    l.push(e);
    l.push(ent);

    while (window.isOpen())
    {
        window.clear();
        l.imprimir(&window);
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
                e->setX(sf::Mouse::getPosition(window).x);
                e->setY(sf::Mouse::getPosition(window).y);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                ent->setX(ent->getX() + 5);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                ent->setX(ent->getX() - 5);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                ent->setY(ent->getY() + 5);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
               ent->setY(ent->getY() - 5);
            }
        }
        e->executar(dt);
        ent->executar(dt);/*
        if(colidindo(e, ent))
        {
            e->vy = 0;
        }
        if(e->y >= 1000)
        {
            e->vy = 0;
        }*/
    }
}
