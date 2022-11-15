#include "Estados.h"

Estado::Estado()
{

}

Estado::~Estado()
{

}

Fase* Estado::pFase = NULL;
Estado* Estado::eInicial= NULL;
Estado* Estado::ePlay= NULL;
Estado* Estado::eLoad= NULL;
