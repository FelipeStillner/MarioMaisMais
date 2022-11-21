#pragma once

#include"Estados.h"

namespace ClassesAuxiliares
{

namespace Estados
{


class Inicial : public Estado
{
private:
    Botao mario;
    Botao play;
    Botao rank;
    Botao quitgame;
public:
    Inicial ();
    ~Inicial ();
    void imprimir();
    Estado* eExecutar();
    Fase* getFase() const;
    void setFase(const int i = 0);
};

}

}
