#pragma once
#include "../../Afix.h"
#include "Elemento.h"

namespace ClassesAuxiliares
{

namespace Listas
{

template <class TIPO>
class Lista
{
private:
  Elemento<TIPO>* pPrimeiro;
  Elemento<TIPO>* pUltimo;
  int tam;
public:
  Lista();
  ~Lista();
  void inicializa();
  bool incluaElemento(Elemento<TIPO>* pElemento); 
  bool incluaInfo(TIPO* pInfo);
  TIPO* operator[](int n); 
  int getSize();
  void limpaLista();
};

}

}

using namespace ClassesAuxiliares;
using namespace Listas;

template <class TIPO>
Lista<TIPO>::Lista()
{
  inicializa();
}

template <class TIPO>
Lista<TIPO>::~Lista()
{
}

template <class TIPO>
void Lista<TIPO>::inicializa()
{
  tam = 0;
  pPrimeiro = NULL;
  pUltimo = NULL;
}

template <class TIPO>
bool Lista<TIPO>::incluaElemento(Elemento<TIPO>* pElemento)
{
  if(NULL != pElemento) 
  {
    if(NULL == pPrimeiro) 
    {
      pPrimeiro = pElemento;
      pUltimo = pPrimeiro; 
    }
    else 
    {
      pElemento->setProximo ( NULL ); 
      pUltimo->setProximo(pElemento); 
      pUltimo = pUltimo->getProximo();
    }
    tam++;
    return true; 
  }
  else 
  {
    std::cout << "Erro, elemento nulo na lista." << std::endl; 
    return false;
  }
}

template <class TIPO>
bool Lista<TIPO>::incluaInfo(TIPO* pInfo)
{
  if(NULL != pInfo) 
  {
    Elemento<TIPO>* pElemento = NULL; 
    pElemento = new Elemento<TIPO>(); 
    pElemento->setInfo(pInfo ); 
    incluaElemento(pElemento );
    return true; 
  }
  else 
  {
    printf ( "Erro, elemento (informação) nulo(a) na lista. \n" );
    return false; 
  }
}

template <class TIPO>
TIPO* Lista<TIPO>::operator[](int n)
{
  if(n > tam)
  {
    return NULL;
  }
  int i = 0;
  Elemento<TIPO>* e = NULL;
  e = pPrimeiro;
  while (e != NULL)
  {
    if(i == n)
    {
      return e->getInfo();
    }
    i++;
    e = e->getProximo();
  }
  return NULL;
}

template <class TIPO>
int Lista<TIPO>::getSize()
{
  return tam;
}

template <class TIPO>
void Lista<TIPO>::limpaLista()
{
  while(pPrimeiro!=NULL)
  {
    Elemento<TIPO>* pAux = pPrimeiro;
    pPrimeiro=pPrimeiro->getProximo();
    delete pAux;
  }
}
