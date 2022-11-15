#pragma once
#include"../../Afix.h"
#include"../../Ente.h"
#include"../Botao.h"
#include"../../Fase.h"
#include"../../Fase1.h"
#include"../../Fase2.h"
class Estado
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
    virtual Estado* executar(sf::Keyboard::Key  pKey = sf::Keyboard::Comma)=0;
    Estado();
    virtual ~Estado();
    static void inicializa();
};
