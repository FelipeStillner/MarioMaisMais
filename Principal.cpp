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
        if(f->getJogando())
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

        // Isso vira o gerenciador de inputs
        while (w.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                w.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                f->getEntidades()->getJogador()->setXX0(sf::Mouse::getPosition(w).x);
                f->getEntidades()->getJogador()->setYY0(sf::Mouse::getPosition(w).y);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            Jogador* p = f->getEntidades()->getJogador();
            p->setXX0(p->getX()+10);
            p->setYY0(p->getY());
            p->setEstado(WALKR);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            Jogador* p = f->getEntidades()->getJogador();
            p->setXX0(p->getX()-10);
            p->setYY0(p->getY());
            p->setEstado(WALKL);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            Jogador* p = f->getEntidades()->getJogador();
            if(p->getVy() == 0)
            {
                p->setVy(-31);
                p->setXX0(p->getX());
                p->setEstado(JUMP);
            }
        }
        else 
        {
            f->getEntidades()->getJogador()->setEstado(IDLE);   
        }
        if(f->getJogando())
            f->executar(dt);
        if(f->getJogando())
            f->gerenciarColisoes();
    }
}
