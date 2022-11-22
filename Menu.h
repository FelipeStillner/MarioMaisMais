#pragma once



//objeto estado!!!!!!
#include "Entidades/Entidade.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Afix.h"
#include "Ente.h"
#include "ClassesAuxiliares/Botao.h"
#include "ClassesAuxiliares/Estados/Estados.h"
#include "ClassesAuxiliares/Estados/Load.h"
#include "ClassesAuxiliares/Estados/Play.h"
#include "ClassesAuxiliares/Estados/Inicial.h"
#include "ClassesAuxiliares/Estados/Pausa.h"
#include "ClassesAuxiliares/Estados/Rank.h"
using std::string;
using std::vector;

class Menu : public Ente
{
protected:
  bool pausado;
  bool mudouEstado;
  Estado* pEstado;
public:
  Menu();
  ~Menu();
  virtual void executar(float dt = 0);
  void imprimir();
  void setPausa(bool p);
  const bool getPausa() const ;
  Fase* getFase();
};


