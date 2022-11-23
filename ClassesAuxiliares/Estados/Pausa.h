#pragma once

#include"Estados.h"
#include"Save.h"
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
    Fase* getFase() const;
    void setFase(const int i = 0);
    void salvarPontuacao();
};

}

}
