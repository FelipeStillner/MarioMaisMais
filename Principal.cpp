#include "Principal.h"

Principal::Principal() : gText(), entes(), w(sf::VideoMode(1600, 1200), "SFML window"), clock()
{
    Personagem *e = new Personagem(1000.0, 1000.0, gText.lista[0], Colisao(10, 10), 1,Animacao(sf::IntRect(0, 0, 30, 30), 0.5, "12"));
    Personagem *ent = new Personagem(2, 0, gText.lista[0], Colisao(10, 10), 1, Animacao(sf::IntRect(0, 0, 30, 30), 0.5, "1242"));
    Projetil *p = new Projetil(0, 0, gText.lista[1], Colisao(1, 1), 10.0, 10.0, 0);
    entes.push(e);
    entes.push(ent);
    entes.push(p);
    executar();
}

Principal::~Principal()
{
}

void Principal::executar()
{
    const float FPS = 60.0;
    float dt ;
    sf::Event event;

    while (w.isOpen())
    {
        w.clear(sf::Color::White);
        entes.imprimir(&w);
        dt = clock.getElapsedTime().asSeconds();  
        if (dt < (1.0 / FPS))
        {
                sf::sleep(sf::seconds((1.0f / FPS) - dt));
                dt = 1.0f / FPS;
        }
        else{std::cout << "FPS\n";}
        clock.restart();
        w.display();

        while (w.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                w.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                static_cast<Personagem*>(entes[0])->setX(sf::Mouse::getPosition(w).x);
                static_cast<Personagem*>(entes[0])->setY(sf::Mouse::getPosition(w).y);
            }/*
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
            }*/
        }
        entes.executar(dt);
    }
}
