#include"Inicial.h"

Inicial ::Inicial () :
mario(sf::Keyboard::Comma,sf::Vector2f(0,0),string("mario++")),
play(sf::Keyboard::Num1,sf::Vector2f(0,8.0*8.0),string("1)PL2AY")),
rank(sf::Keyboard::Num2,sf::Vector2f(0,8.0*8.0*2),string("2)RANK")),
quitgame(sf::Keyboard::Num3,sf::Vector2f(0,8.0*8.0*3),string("3)QUIT"))
{

}
void Inicial ::imprimir()
{
    mario.escreveTexto();
    play.escreveTexto();
    rank.escreveTexto();
    quitgame.escreveTexto();
}
Estado* Inicial ::executar(sf::Keyboard::Key  pKey)
{   
    //if(sf::Keyboard::isKeyPressed(play.getOpt()))
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))        
        {
            return(ePlay);
        
        }
    //else if (sf::Keyboard::isKeyPressed(rank.getOpt()))
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        {
            return(this);
        }
    //else if (sf::Keyboard::isKeyPressed(quitgame.getOpt()))
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
        {
            return(NULL);
        }
    else
        {
            return (this);
        }

}

Inicial ::~Inicial ()
{
    
}
