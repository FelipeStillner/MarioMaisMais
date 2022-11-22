#include "Menu.h"

/*
    Bom dia

    Jogar
        n jogadores? 1 ou 2

        Fases? Mapas?




    Opcoes

    Ranking


*/
Menu::Menu() : Ente()
{
    mudouEstado = false;
    setPausa(true);
    int frstL = '!';
    int i, j;
    Botao::inicializaLetras();
    Estado::eInicial= new Inicial;
    Estado::ePlay= new Play;
    Estado::eLoad= new Load;
    Estado::ePausa= new Pausa;
    Estado::eRank= new Rank;
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
    if(mudouEstado)
    {
        sf::sleep(sf::seconds(0.4));
        mudouEstado = false;
    }
    Estado* e = pEstado;
    pEstado = pEstado->eExecutar();
    if(e != pEstado)
    {
        mudouEstado = true;
    }
    if(!pEstado)
    {
        gG->getWindow()->close();
    }
    if(pEstado->getFase())
    {
        if(pEstado->getFase()->getGanhou())
        {
            //salvarPontuacao();
            if(pEstado->getFase()->getTipo() == FASE1)
            {
                pEstado->getFase()->limpaFase();
                pEstado->getFase()->~Fase();
                pEstado->setFase(2);
            }
        }
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

