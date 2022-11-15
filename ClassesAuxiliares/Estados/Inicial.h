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
    Estado* eExecutar(sf::Keyboard::Key  pKey = sf::Keyboard::Comma);
    Fase* getFase();
    void setFase(int i = 0);
};
