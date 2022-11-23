#pragma once

#include"../../Afix.h"
#include"../../Ente.h"
#include"../Botao.h"
#include"../../Fases/Fase.h"
#include"../../Fases/Fase1.h"
#include"../../Fases/Fase2.h"

namespace ClassesAuxiliares
{

namespace Estados
{

class Estado : public Ente 
{
public:
    static  Fase* pFase;
    static  Estado* eInicial;
    static  Estado* ePlay;
    static  Estado* eLoad;
    static  Estado* ePausa;
    static  Estado* eRank;
    static  Estado* eSave; 

public: 
    Estado();
    virtual ~Estado();
    virtual void imprimir() = 0;
    virtual Estado* eExecutar() = 0;
    virtual void executar(const float dt = 0);
    static void inicializa();
    virtual Fase* getFase() const = 0;
    virtual void setFase(const int i = 0) = 0;
};

}

}

using namespace ClassesAuxiliares;

using namespace Estados;