#include "Principal.h"

Principal::Principal() : gGraf(NULL), w(NULL), clock(), gEven(NULL), menu(NULL)
{
    gEven = new GerenciadorEventos(this);
    gGraf = new GerenciadorGrafico();
    w = new sf::RenderWindow(sf::VideoMode(1920, 1080), "SFML window");
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

    while (w->isOpen())
    {
        if(f->getJogando())
            f->imprimir(w);
        //menu.imprimir(&w);
        if(f->getEntidades()->getJogador()->getVida() < 0)
        {
            //f->setJogando(false);
        }
        w->setView(sf::View(sf::Vector2f(f->getEntidades()->getJogador()->getX(), f->getEntidades()->getJogador()->getY()), sf::Vector2f(1920, 1080)));
        
        dt = clock.getElapsedTime().asSeconds();  
        if (dt < (1.0 / FPS))
        {
            sf::Time t = sf::seconds((1.0f / FPS) - dt);
            sf::sleep(t);
            dt = 1.0f / FPS;
        }
        else{std::cout << "FPS\n";}
        clock.restart();
        w->display();

        gEven->executar();
        
        if(f->getJogando())
            f->executar(dt);
        if(f->getJogando())
            f->gerenciarColisoes();
    }
}

void Principal::setWindow(sf::RenderWindow* w)
{
    this->w = w;
}

void Principal::setGerenciadorEventos(GerenciadorEventos *gEven)
{
    this->gEven = gEven;
}

void Principal::setGerenciadorGrafico(GerenciadorGrafico *gGraf)
{
    this->gGraf = gGraf;
}

void Principal::setMenu(Menu *menu)
{
    this->menu = menu;
}

void Principal::setFase(Fase *f)
{
    this->f = f;
}

sf::RenderWindow* Principal::getWindow()
{
    return w;
}

GerenciadorEventos* Principal::getGerenciadorEventos()
{
    return gEven;
}

GerenciadorGrafico* Principal::getGerenciadorGrafico()
{
    return gGraf;
}

Menu* Principal::getMenu()
{
    return menu;
}

Fase* Principal::getFase()
{
    return f;
}