#include"Load.h"

Load ::Load () :
fase1(sf::Keyboard::Num1,sf::Vector2f(0,0),string("1)FASE 1")),
fase2(sf::Keyboard::Num2,sf::Vector2f(0,8.0*8.0),string("2)FASE 2")),
back(sf::Keyboard::Num3,sf::Vector2f(0,8.0*8.0*2),string("3)BACK"))
{

}
void Load ::imprimir()
{
    fase1.escreveTexto();
    fase2.escreveTexto();
    back.escreveTexto();
}
Estado* Load ::eExecutar(sf::Keyboard::Key  pKey)
{   //

    //if (sf::Keyboard::isKeyPressed(fase1.getOpt()))
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        {
            setFase(1);
            return(eInicial); 
        }
    //else if (sf::Keyboard::isKeyPressed(fase2.getOpt()))
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        {
            setFase(2);
            return(eInicial);
        }
    //else if (sf::Keyboard::isKeyPressed(back.getOpt()))
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
        {
            return(eInicial);
        }
    else
        {
            return (this);
        }
}
void  Load::setFase(int i )
{
    if(i==1)
    {
        pFase = new Fase1();
        pFase ->recFase();
    }
    else if( i ==2)
    {
        pFase = new Fase2();
        pFase ->recFase();
    }
}
Fase* Load::getFase()
{
    return(pFase);
}
Load ::~Load ()
{

}
