#pragma once

#include "../Afix.h"
#include "../Ente.h"
#include "../ClassesAuxiliares/ListaEntidades.h"
#include "../Gerenciadores/GerenciadorColisoes.h"
#include "../Entidades/Personagens/Andador.h"
#include "../Entidades/Obstaculos/Chao.h"
#include "../Entidades/Obstaculos/Tubo.h"
#include "../Entidades/Personagens/Jogador.h"
#include "../Entidades/Obstaculos/Bandeira.h"

class Principal;

namespace Fases
{

class Fase : public Ente
{
protected:
  GerenciadorColisoes gCol;
  sf::Texture* background;
  ListaEntidades entidades;
  Jogador* jog;
  Jogador* jog2;
  bool jogando;
  bool mltply;
public:
  Fase();
  virtual ~Fase();
  virtual void executar(float dt);
  virtual void imprimir();
  void gerenciarColisoes();
  ListaEntidades* getEntidades();
  bool getJogando();
  void setJogando(bool n);
  Jogador* getJogador(int i = 1);
  void setJogador(Jogador* j,int i = 1);
  void setMltplyr(bool m = false);
  const bool getMltplyr() const ;
  Jogador* createJogador(float x = 0, float y = 0);
  Chao* createChao(float x = 0, float y = 0);
  Tubo* createTubo(float x = 0, float y = 0);
  Projetil* createProjetil(float x = 0, float y = 0);
  Bandeira* createBandeira(float x = 0, float y = 0);
  void setBackground(int i = 3);
  const int getIBackground() const;
  virtual void gravaFase()= 0;
  virtual Fase* recFase() = 0;
  GerenciadorColisoes* getGCol();
};

}

using namespace Fases;