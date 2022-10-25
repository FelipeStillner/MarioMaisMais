#include "Principal.h"

Principal::Principal() : gText(), entes(), w(sf::VideoMode(1920, 1080), "SFML window"), clock()
{
    Jogador *e = new Jogador(1000.0, 500.0, gText.texturas[0], Colisao(160, 320), 1,Animacao(sf::IntRect(0, 0, 16, 32), 0.25, "1232"));
    Projetil *p = new Projetil(0, 0, gText.texturas[1], Colisao(80, 80), 200.0, 100.0, 0);
    Obstaculo *o = new Obstaculo(1000.0, 800.0, gText.texturas[2], Colisao(320, 320));
    Obstaculo *c = new Obstaculo(0.0, 900.0, gText.texturas[5], Colisao(1920, 320));
    Inimigo *i = new Inimigo(1000.0, 600.0, gText.texturas[4], Colisao(160, 160), 1,Animacao(sf::IntRect(0, 0, 16, 16), 0.25, "12"));
    entes.push(e);
    entes.push(p);
    entes.push(o);
    entes.push(c);
    entes.push(i);
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
        sf::RectangleShape r;
        r.setOrigin(0, 0);
        r.setSize(sf::Vector2f(w.getSize().x, w.getSize().y));
        r.setTexture(gText.texturas[3]);
        w.draw(r);
        entes.imprimir(&w);
        dt = clock.getElapsedTime().asSeconds();  
        if (dt < (1.0 / FPS))
        {
            sf::Time t = sf::seconds((1.0f / FPS) - dt);
            sf::sleep(t);
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
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            Personagem* p = static_cast<Personagem*>(entes[0]);
            p->setX(p->getX()+10);
            p->setY(p->getY());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            Personagem* p = static_cast<Personagem*>(entes[0]);
            p->setX(p->getX()-10);
            p->setY(p->getY());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            Personagem* p = static_cast<Personagem*>(entes[0]);
            p->setY(p->getY()-10);
            p->setX(p->getX());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            Personagem* p = static_cast<Personagem*>(entes[0]);
            p->setY(p->getY()+10);
            p->setX(p->getX());
        }
        for (int i = 0; i < entes.getLista().size(); i++)
        {
            for (int j = i+1; j < entes.getLista().size(); j++)
            {
                Entidade *e1 = static_cast<Entidade*>(entes[i]),
                    *e2 = static_cast<Entidade*>(entes[j]);
                if (colidindo(e1, e2) || colidindo(e2, e1))
                {
                    e1->setX(e1->getX0());
                    e2->setX(e2->getX0());
                    e1->setY(e1->getY0());
                    e2->setY(e2->getY0());
                    e1->setX(e1->getX());
                    e2->setX(e2->getX());
                    e1->setY(e1->getY());
                    e2->setY(e2->getY());
                }
            }
        }
        entes.executar(dt);
    }
}
