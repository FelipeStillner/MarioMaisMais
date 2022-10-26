#include "Principal.h"

Principal::Principal() : gGraf(), entidades(), w(sf::VideoMode(1920, 1080), "SFML window"), clock()
{
    Jogador *e = new Jogador(this, 1000.0, 500.0, 160, 320, gGraf.texturas[0], Colisao(10, 10, 140, 300), 1,Animacao(sf::IntRect(0, 0, 16, 32), 0.25, "1232"));
    Projetil *p = new Projetil(0, 0, 80, 80, gGraf.texturas[1], Colisao(10, 10, 60, 60), 200.0, 100.0, 0);
    Obstaculo *o = new Obstaculo(1000.0, 800.0, 320, 320, gGraf.texturas[2], Colisao(10, 10, 300, 300));
    Obstaculo *c = new Obstaculo(0.0, 900.0, 1920, 320, gGraf.texturas[5], Colisao(10, 10, 1900, 300));
    Inimigo *i = new Inimigo(1000.0, 600.0, 160, 160, gGraf.texturas[4], Colisao(10, 10, 140, 140), 1,Animacao(sf::IntRect(0, 0, 16, 16), 0.25, "12"));
    entidades.push(e);
    entidades.push(p);
    entidades.push(o);
    entidades.push(c);
    entidades.push(i);
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
        r.setTexture(gGraf.texturas[3]);
        w.draw(r);
        entidades.imprimir(&w);
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
                static_cast<Personagem*>(entidades[0])->setXX0(sf::Mouse::getPosition(w).x);
                static_cast<Personagem*>(entidades[0])->setYY0(sf::Mouse::getPosition(w).y);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            Jogador* p = static_cast<Jogador*>(entidades[0]);
            p->setXX0(p->getX()+10);
            p->setYY0(p->getY());
            p->setEstado(WALKR);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            Jogador* p = static_cast<Jogador*>(entidades[0]);
            p->setXX0(p->getX()-10);
            p->setYY0(p->getY());
            p->setEstado(WALKL);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            Jogador* p = static_cast<Jogador*>(entidades[0]);
            p->setYY0(p->getY()-10);
            p->setXX0(p->getX());
            p->setEstado(CLIMB);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            Jogador* p = static_cast<Jogador*>(entidades[0]);
            p->setYY0(p->getY()+10);
            p->setXX0(p->getX());
            p->setEstado(CLIMB);
        }
        else 
        {
            static_cast<Jogador*>(entidades[0])->setEstado(IDLE);   
        }
        entidades.executar(dt);

        
        for (int i = 0; i < entidades.getLista().size(); i++)
        {
            for (int j = i+1; j < entidades.getLista().size(); j++)
            {
                Entidade *e1 = static_cast<Entidade*>(entidades[i]),
                    *e2 = static_cast<Entidade*>(entidades[j]);
                if (colidindo(e1, e2) || colidindo(e2, e1))
                {
                    // Muito ruim
                    e1->setX(e1->getX0());
                    e2->setX(e2->getX0());
                    e1->setY(e1->getY0());
                    e2->setY(e2->getY0());
                }
            }
        }
    }
}
