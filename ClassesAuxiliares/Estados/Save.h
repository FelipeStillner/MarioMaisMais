#pragma once

#include "Estados.h"
#include <string>

using std::string;

namespace ClassesAuxiliares
{

namespace Estados
{

class Save : public Estado 
{
private:
    string nome1 ;
    string nome2 ;
    bool entrou ;
public:
    Save ();
    ~Save ();
    void imprimir();
    Estado* eExecutar();
    Fase* getFase() const;
    void setFase(int i = 0);
    virtual void executar(const float dt = 0);
    void salvarPontuacao();
    void limpaSave();
};

}

}