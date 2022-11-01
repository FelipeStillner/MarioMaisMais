#include "Principal.h"

Principal::Principal() : gGraf(), w(sf::VideoMode(1920, 1080), "SFML window"), clock()
{
    f = new Fase1(this);
    //menu = Menu(&gGraf);
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
        //menu.imprimir(&w);
        
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
                f->entidades.getJogador()->setXX0(sf::Mouse::getPosition(w).x);
                f->entidades.getJogador()->setYY0(sf::Mouse::getPosition(w).y);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            Jogador* p = f->entidades.getJogador();
            p->setXX0(p->getX()+10);
            p->setYY0(p->getY());
            p->setEstado(WALKR);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            Jogador* p = f->entidades.getJogador();
            p->setXX0(p->getX()-10);
            p->setYY0(p->getY());
            p->setEstado(WALKL);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            Jogador* p = f->entidades.getJogador();
            if(p->vy == 0)
            {
                p->vy = -31;
                p->setXX0(p->getX());
                p->setEstado(JUMP);
            }
        }
        else 
        {
            f->entidades.getJogador()->setEstado(IDLE);   
        }
        if(f->isPlaying)
            f->executar(dt);
        
        // Isso vai virar o gerenciador de colisoes
        
        for (int i = 0; i < f->entidades.size(); i++)
        {
            for (int j = i+1; j < f->entidades.size(); j++)
            {
                Entidade *e1 = f->entidades[i],
                    *e2 = f->entidades[j];
                if (colidindo(e1, e2) || colidindo(e2, e1))
                {
                    e1->setY(e1->getY0());
                    e2->setY(e2->getY0());
                    e1->vy = 0;
                    e2->vy = 0;
                } 

            }
        }
        if(f->isPlaying)
            f->gerenciarColisoes();
    }
}
