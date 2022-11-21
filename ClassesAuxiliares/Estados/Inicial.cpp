#include"Inicial.h"

Inicial::Inicial() :
    mario(sf::Vector2f(0,0),string("mario++")),
    play(sf::Vector2f(0,8.0*8.0),string("1)PLAY")),
    rank(sf::Vector2f(0,8.0*8.0*2),string("2)RANK")),
    quitgame(sf::Vector2f(0,8.0*8.0*3),string("3)QUIT"))
{

}

void Inicial::imprimir()
{
    mario.escreveTexto();
    play.escreveTexto();
    rank.escreveTexto();
    quitgame.escreveTexto();
}

Estado* Inicial::eExecutar()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))        
    {
        return(ePlay);
    
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
    {
        return(this);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
    {   
        gG->getWindow()->close();
        return(this);
    }
    else
    {
        return (this);
    }
}

Inicial::~Inicial ()
{
    
}

Fase* Inicial::getFase() const
{
    return (pFase);
}

void Inicial::setFase(const int i)
{
    pFase=NULL;
}