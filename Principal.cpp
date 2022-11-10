#include "Principal.h"

Principal::Principal() : gG(NULL), /*w(NULL),*/ clock(), gEven(NULL)/*, menu(NULL)*/
{
    gEven = new GerenciadorEventos(this);
    gG = new GerenciadorGrafico();
    gF = new GerenciadorFases();
    Ente::setg(gG);
    
    menu = new Menu();
    Menu::inicializaLetras();
  
    
    //f = new Fase1(this);
    f = gF->getFase(1);
    //Menu menu;
    //menu->setg(gG);
    executar();
}

Principal::~Principal()
{
    Menu::destroiLetras();
}

void Principal::executar()
{
    const float FPS = 60.0;
    float dt ;
    sf::RenderWindow* w = gG->getWindow();
    menu->setPausa(false);
    menu->setEstado(INICIAL);
    f->imprimir();
    //gF->gravaFase(f);
    //delete f;
    f = gF->recFase();
    //f->setJogando(false);
    while (w->isOpen())
    {
        if(f->getJogando())
            f->imprimir();
            menu->imprimir();
        
        //menu->setPausa(false);
        //if(menu->getPausa()){menu->imprimir();}
        if(f->getJogador(1)->getVida() < 0 || f->getMltplyr() && f->getJogador(2)->getVida() < 0)
        {
            //f->setJogando(false);
        }
        w->setView(sf::View(sf::Vector2f(f->getJogador()->getX(), w->getSize().y/2), sf::Vector2f(w->getSize())));
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