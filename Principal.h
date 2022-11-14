#pragma once

#include "Afix.h"
#include "ClassesAuxiliares/ListaEntidades.h"
#include "Entidades/Obstaculo.h"
#include "Entidades/Projetil.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Entidades/Jogador.h"
#include "Entidades/Inimigo.h"
#include "Entidades/Tubo.h"
#include "Entidades/Chao.h"
#include "Entidades/Andador.h"
#include "Entidades/Lancador.h"
#include "Entidades/Tartaruga.h"
#include "Entidades/Mola.h"
#include "Entidades/Bandeira.h"
#include "Entidades/Spike.h"
#include "Gerenciadores/GerenciadorEventos.h"
#include "Gerenciadores/GerenciadorFases.h"
#include "Fase1.h"
#include "Fase2.h"
#include "Menu.h"

class Principal
{
private:
  Fase* f;
  sf::Clock clock;
  GerenciadorEventos* gEven;
  GerenciadorGrafico* gG;
  GerenciadorFases* gF;
  Menu* menu;
public:
  Principal();
  ~Principal();
  void executar();
  void setGerenciadorEventos(GerenciadorEventos *gEven);
  void setGerenciadorGrafico(GerenciadorGrafico *gG);
  void setMenu(Menu *menu);
  void setFase(Fase *f);
  GerenciadorEventos* getGerenciadorEventos();
  GerenciadorGrafico* getGerenciadorGrafico();
  Menu* getMenu();
  Fase* getFase();
};
