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
    Estado::eSave = new Save;
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
            if(pEstado->getFase()->getTipo() == FASE1)
            {
                int pont = pEstado->getFase()->getJogador(1)->getPont(), pont2 = -1;
                if(pEstado->getFase()->getMltplyr())
                {
                    pont2 = pEstado->getFase()->getJogador(2)->getPont();
                }
                pEstado->getFase()->limpaFase();
                pEstado->getFase()->~Fase();
                pEstado->setFase(2);
                pEstado->getFase()->getJogador(1)->somaPont(pont);
                if(pont2 >= 0)
                {
                    pEstado->getFase()->getJogador(2)->somaPont(pont2);
                }
                pausado = true;
                pEstado->getFase()->setJogando(false);
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
    int x = -gG->getWindow()->getView().getCenter().x + gG->getWindow()->getSize().x/2,
        y = -gG->getWindow()->getView().getCenter().y + gG->getWindow()->getSize().y/2;
    sf::RectangleShape r;
    r.setTexture((*gG)[22]);
    r.setSize(sf::Vector2f(gG->getWindow()->getSize()));
    r.setOrigin(x, y);
    gG->getWindow()->draw(r);
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
