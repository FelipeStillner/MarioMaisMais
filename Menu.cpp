#include "Menu.h"

/*
    Bom dia

    Jogar
        n jogadores? 1 ou 2

        Fases? Mapas?




    Opcoes

    Ranking


*/
Menu::Menu(int k) : Ente()
{
    setPausa(true);
    int frstL = '!';
    int i, j;
    Botao::inicializaLetras();
    Estado::eInicial= new Inicial;
    Estado::ePlay= new Play;
    Estado::eLoad= new Load;
    pEstado = Estado::eInicial;
}

Menu::~Menu()
{
    Botao::destroiLetras();
}

void Menu::executar(float dt)
{
    sf::Event event;
    sf::RenderWindow *rw = (gG->getWindow());
    rw->pollEvent(event);
    sf::sleep(sf::seconds(0.8));
    pEstado=pEstado->eExecutar();
    if(!pEstado)
    {
        setPausa(false);
    }
}

Fase* Menu::getFase()
{
    return(pEstado->getFase());
}
  
void Menu::imprimir()
{
    pEstado->imprimir();
}

void Menu::setPausa(bool p)
{
    pausado = p;
}

const bool Menu::getPausa() const
{
    return (pausado);
}
