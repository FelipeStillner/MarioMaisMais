#include "Principal.h"

Principal::Principal() : gG(NULL), clock(), gEven(NULL), menu(NULL)
{
    gEven = new GerenciadorEventos(this);
    gG = new GerenciadorGrafico();
    Ente::setg(gG);
    
    menu = new Menu();
    f = NULL;
    menu->setg(gG);
    executar();
}

Principal::~Principal()
{

}

void Principal::executar()
{
    const float FPS = 60.0;
    float dt ;
    sf::RenderWindow* w = gG->getWindow();
    //menu->setEstado(INICIAL);
    //f->imprimir();
    //gF->gravaFase(f);
    //delete f;
    //f = gF->recFase();
    //f->setJogando(false);
    while (w->isOpen())
    {
        w->clear(sf::Color(0, 0 ,0));
        if(menu->getPausa())
        {
            menu->imprimir();
        }
        else
        {
            if(f->getJogando())
            {
                f->imprimir();
            }
            else
            {
                menu->imprimir();
            }
        }
        if(f)
        {   
            if(f->getJogador(1)->getVida() <= 0 || (f->getMltplyr() && f->getJogador(2)->getVida() <= 0))
                {
                    f->setJogando(false);
                }
            if(f->getJogando())
            {
            w->setView(sf::View(sf::Vector2f(f->getJogador()->getX(), w->getSize().y/2), sf::Vector2f(w->getSize())));
            }
        }
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

        if(menu->getPausa())
        {
            menu->executar();
            f = menu->getFase();
            if(f){menu->setPausa(false);}
        }
        else
        {
            if(f&&(f->getJogando()))
            {    
                f->executar(dt);
                f->gerenciarColisoes();
            }
            else
            {
                menu->executar();
                f = menu->getFase();
            }
        }
    }
}

void Principal::setGerenciadorEventos(GerenciadorEventos *gEven)
{
    this->gEven = gEven;
}

void Principal::setGerenciadorGrafico(GerenciadorGrafico *gG)
{
    this->gG = gG;
}

void Principal::setMenu(Menu *menu)
{
    this->menu = menu;
}

void Principal::setFase(Fase *f)
{
    this->f = f;
}

GerenciadorEventos* Principal::getGerenciadorEventos()
{
    return gEven;
}

GerenciadorGrafico* Principal::getGerenciadorGrafico()
{
    return gG;
}

Menu* Principal::getMenu()
{
    return menu;
}

Fase* Principal::getFase()
{
    return f;
}