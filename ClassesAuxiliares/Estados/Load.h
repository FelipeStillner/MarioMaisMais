#pragma once

#include"Estados.h"

namespace ClassesAuxiliares
{

namespace Estados
{


class Load : public Estado
{
private:
    Botao fase1;
    Botao fase2;
    Botao back;
public:
    Load ();
    ~Load ();
    void imprimir();
    Estado* eExecutar();
    void setFase(const int i = 0);
    Fase* getFase() const;
};

}

}
