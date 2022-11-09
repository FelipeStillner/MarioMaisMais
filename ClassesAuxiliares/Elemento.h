#pragma once

namespace ClassesAuxiliares
{

template <class TIPO>
class Elemento
{
private:
  Elemento<TIPO>* pProx;
  TIPO* pInfo;
public:
  Elemento();
  ~Elemento();
  void setProximo(Elemento<TIPO>* pp); 
  Elemento<TIPO>* getProximo();
  void setInfo(TIPO* pi ); 
  TIPO* getInfo();
};

}

using namespace ClassesAuxiliares;


template <class TIPO>
Elemento<TIPO>::Elemento()
{
  pProx = NULL; 
  pInfo = NULL;
}

template <class TIPO>
Elemento<TIPO>::~Elemento()
{
}

template <class TIPO>
void Elemento<TIPO>::setProximo(Elemento<TIPO>* pp)
{
  pProx = pp;
}

template <class TIPO>
Elemento<TIPO>* Elemento<TIPO>::getProximo()
{
  return pProx;
}

template <class TIPO>
void Elemento<TIPO>::setInfo(TIPO* pi)
{
  pInfo = pi;
}

template <class TIPO>
TIPO* Elemento<TIPO>::getInfo()
{
  return pInfo;
}
