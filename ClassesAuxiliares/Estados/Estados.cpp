#include "Estados.h"

Estado::Estado()
{
    pFase = NULL;
}

Estado::~Estado()
{
}

Fase* Estado::pFase = NULL;
Estado* Estado::eInicial= NULL;
Estado* Estado::ePlay= NULL;
Estado* Estado::eLoad= NULL;
Estado* Estado::ePausa= NULL;
Estado* Estado::eRank = NULL;
Estado* Estado::eSave = NULL;
void Estado::executar(float dt)
{

}
