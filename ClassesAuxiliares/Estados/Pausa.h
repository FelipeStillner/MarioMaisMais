#pragma once

#include"Estados.h"

namespace ClassesAuxiliares
{

namespace Estados
{

class Pausa : public Estado
{
private:
    Botao resume;
    Botao save;
    Botao quit;
public:
    Pausa ();
    ~Pausa ();
    void imprimir();
    Estado* eExecutar();
    Fase* getFase();
    void setFase(int i = 0);
};

}

}
