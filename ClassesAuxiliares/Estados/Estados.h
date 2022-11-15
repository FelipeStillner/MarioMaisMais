#pragma once
#include"../../Afix.h"
#include"../../Ente.h"
#include"../Botao.h"
#include"../../Fase.h"
#include"../../Fase1.h"
#include"../../Fase2.h"
class Estado : public Ente 
{
//protected:
public: 
    static Fase* pFase;
    static Estado* eInicial;
    static  Estado* ePlay;
    static  Estado* eLoad;
    //static Inicial* eInicial;
    //static  Play* ePlay;
    //static  Load* eLoad;
    virtual void imprimir()=0;
    virtual Estado* eExecutar(sf::Keyboard::Key  pKey = sf::Keyboard::Comma)=0;
    virtual void executar(float dt =0 );
    Estado();
    virtual ~Estado();
    static void inicializa();
    virtual  Fase* getFase() = 0;
    virtual  void setFase(int i = 0)=0;
};
