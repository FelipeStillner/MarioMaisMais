#pragma once
#include<map>
#include"Estados.h"
using std::multimap;
using std::pair;
namespace ClassesAuxiliares
{

typedef multimap<int, string, std::greater<int> > mMapa ;
typedef pair<int,string> mPar;

namespace Estados
{

class Rank : public Estado
{
private:
    vector<Botao*> botoes;
    Botao back;
    mMapa mapa;
public:
    Rank ();
    ~Rank ();
    void imprimir();
    Estado* eExecutar();
    Fase* getFase() const;
    void setFase(int i = 0);
    virtual void executar(const float dt = 0);
    void salvarPontuacao();
    void limpaBotoes();
};

}

}