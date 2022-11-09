#pragma once
#include "../Afix.h"
#include "../Fase.h"
#include "../Fase1.h"
#include "../Ente.h"
#include<fstream>

using  std::cout; using std::cin; using  std::ios; using  std::fstream;

namespace Gerenciadores
{

class GerenciadorFases 
{
    private:
        Fase1 * fase1;
        Fase* fase;
        Principal* pP;

    public:
        GerenciadorFases();
        ~GerenciadorFases();
        Fase* recFase();
        void gravaFase(Fase* f);
        Fase* getFase(int i = 1);
};

}
