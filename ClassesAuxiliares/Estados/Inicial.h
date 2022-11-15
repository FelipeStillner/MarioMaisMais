#pragma once

#include"Estados.h"
class Inicial : public Estado
{
private:
    Botao mario;
    Botao play;
    Botao rank;
    Botao quitgame;
    //Estado* 
    //Estado*
    //Estado*
public:
    Inicial ();
    ~Inicial ();
    void imprimir();
    Estado* executar(sf::Keyboard::Key  pKey = sf::Keyboard::Comma);
};
