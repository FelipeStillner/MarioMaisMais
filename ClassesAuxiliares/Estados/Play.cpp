#include"Play.h"

Play::Play () :
fase1(sf::Vector2f(0,0),string("1)FASE 1")),
fase2(sf::Vector2f(0,8.0*8.0),string("2)FASE 2")),
load(sf::Vector2f(0,8.0*8.0*2),string("3)LOAD")),
back(sf::Vector2f(0,8.0*8.0*3),string("4)GO BACK"))
{

}
Play::~Play ()
{

}
void Play ::imprimir()
{
    fase1.escreveTexto();
    fase2.escreveTexto();
    load.escreveTexto();
    back.escreveTexto();
}
Estado* Play::eExecutar()
{   
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
    {
        setFase(1);
        return (ePausa);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
    {
        setFase(2);
        return (ePausa);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
    {
        return(eLoad);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
    {
        return(eInicial);
    }
    else
    {
        return (this);
    }
}
void  Play::setFase(const int i)
{
    if(i == 1)
    {
        pFase = new Fase1();
    }
    else if(i == 2)
    {

        pFase = new Fase2();
    }
}
Fase* Play::getFase() const
{
    return(pFase);
}

