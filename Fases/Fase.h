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
#include "../Entidades/Personagens/Luigi.h"
#include "../Entidades/Personagens/Tartaruga.h"
#include "../Entidades/Obstaculos/Spike.h"

class Principal;

namespace Fases
{

class Fase : public Ente
{
public:
  class Hud : public Ente
  {
  private:
    Fase* f;
  public:
    Hud(Fase* f);
    ~Hud();
    virtual void imprimir();
    virtual void executar(float dt = 0);
  };
protected:
  GerenciadorColisoes gCol;
  sf::Texture* background;
  ListaEntidades entidades;
  Jogador* jog;
  Jogador* jog2;
  Hud h;
  bool jogando;
  bool mltply;
  bool ganhou;
public:
  Fase();
  virtual ~Fase();
  virtual void executar(float dt);
  virtual void imprimir();
  void gerenciarColisoes();
  ListaEntidades* getEntidades();
  bool getJogando();
  void setJogando(bool n);
  bool getGanhou();
  void setGanhou(bool n);
  Jogador* getJogador(int i = 1);
  void setJogador(Jogador* j,int i = 1);
  void setMltplyr(bool m = false);
  const bool getMltplyr() const ;
  Jogador* createJogador(float x = 0, float y = 0);
  Chao* createChao(float x = 0, float y = 0);
  Tubo* createTubo(float x = 0, float y = 0);
  Projetil* createProjetil(float x = 0, float y = 0);
  Bandeira* createBandeira(float x = 0, float y = 0);
  Spike* createSpike(float x = 0 , float y = 0);
  void setBackground(int i = 3);
  const int getIBackground() const;
  virtual void gravaFase()= 0;
  virtual Fase* recFase() = 0;
  GerenciadorColisoes* getGCol();
  void limpaFase();
  virtual int getTipo() = 0;
  Tartaruga* createTartaruga(float x = 0 , float y = 0);
};

}

using namespace Fases;