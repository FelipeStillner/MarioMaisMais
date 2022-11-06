#pragma once

#include "Afix.h"
#include "ClassesAuxiliares/ListaEntidades.h"
#include "Entidades/Obstaculo.h"
#include "Entidades/Projetil.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Entidades/Jogador.h"
#include "Entidades/Inimigo.h"
#include "Gerenciadores/GerenciadorEventos.h"
#include "Fase1.h"
#include "Menu.h"

class Principal
{
private:
  Fase* f;
  sf::Clock clock;
  GerenciadorEventos* gEven;
  GerenciadorGrafico* gG;
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
