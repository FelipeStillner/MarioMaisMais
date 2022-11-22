#pragma once

#include "Afix.h"
#include "ClassesAuxiliares/ListaEntidades.h"
#include "Entidades/Obstaculos/Obstaculo.h"
#include "Entidades/Projetil.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Entidades/Personagens/Jogador.h"
#include "Entidades/Personagens/Inimigo.h"
#include "Entidades/Obstaculos/Tubo.h"
#include "Entidades/Obstaculos/Chao.h"
#include "Entidades/Personagens/Andador.h"
#include "Entidades/Personagens/Lancador.h"
#include "Entidades/Personagens/Tartaruga.h"
#include "Entidades/Obstaculos/Mola.h"
#include "Entidades/Obstaculos/Bandeira.h"
#include "Entidades/Obstaculos/Spike.h"
#include "Gerenciadores/GerenciadorEventos.h"
#include "Fases/Fase1.h"
#include "Fases/Fase2.h"
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
