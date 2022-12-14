#pragma once

#include"Estados.h"

namespace ClassesAuxiliares
{

namespace Estados
{

class Play : public Estado
{
private:
    Botao fase1;
    Botao fase2;
    Botao load;
    Botao back;
public:
    Play ();
    ~Play ();
    void imprimir();
    Estado* eExecutar();
    Fase* getFase() const;
    void setFase(const int i = 0);
};

}

}
