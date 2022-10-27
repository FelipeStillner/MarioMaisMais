#pragma once

#include "Afix.h"
#include "ClassesAuxiliares/ListaEntidades.h"
#include "Entidades/Obstaculo.h"
#include "Entidades/Projetil.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Entidades/Jogador.h"
#include "Entidades/Inimigo.h"
#include "Gerenciadores/GerenciadorEventos.h"
// #include "Menu.h"

class Principal
{
private:
  ListaEntidades entidades;
  sf::Clock clock;
public:
  sf::RenderWindow w;
  GerenciadorEventos gEven;
  GerenciadorGrafico gGraf;
public:
  Principal();
  ~Principal();
  void executar();
};
