#include "Principal.h"

Principal::Principal() : gGraf(), w(sf::VideoMode(1920, 1080), "SFML window"), clock()
{
    f = new Fase1(this);
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
        if(f->isPlaying)
            f->imprimir(&w);
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
                f->jog->setXX0(sf::Mouse::getPosition(w).x);
                f->jog->setYY0(sf::Mouse::getPosition(w).y);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            Jogador* p = f->jog;
            p->setXX0(p->getX()+10);
            p->setYY0(p->getY());
            p->setEstado(WALKR);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            Jogador* p = f->jog;
            p->setXX0(p->getX()-10);
            p->setYY0(p->getY());
            p->setEstado(WALKL);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            Jogador* p = f->jog;
            if(p->vy == 0)
            {
                p->vy = -31;
                p->setXX0(p->getX());
                p->setEstado(JUMP);
            }
        }
        else 
        {
            f->jog->setEstado(IDLE);   
        }
        if(f->isPlaying)
            f->executar(dt);
        
        for (int i = 0; i < f->entidades.getLista().size(); i++)
        {
            for (int j = i+1; j < f->entidades.getLista().size(); j++)
            {
                Entidade *e1 = f->entidades[i],
                    *e2 = f->entidades[j];
                int c1 = colidindo(e1, e2), c2 = colidindo(e2, e1);
                if (c1 == CIMA || c2 == BAIXO)
                {
                    e1->setY(e1->getY0());
                    e2->setY(e2->getY0());
                    e1->vy = 0;
                    e2->vy = 0;
                }
                else if (c1 == BAIXO || c2 == CIMA)
                {
                    e2->setY(e2->getY0());
                    e1->setY(e1->getY0());
                    e1->vy = 0;
                    e2->vy = 0;
                }
                if (c1 == DIREITA || c2 == ESQUERDA)
                {
                    e1->setX(e1->getX0());
                    e2->setX(e2->getX0());
                }
                else if (c1 == ESQUERDA || c2 == DIREITA)
                {
                    e2->setX(e2->getX0());
                    e1->setX(e1->getX0());
                }
            }
        }
    }
}
