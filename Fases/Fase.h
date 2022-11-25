#pragma once

#include "../Afix.h"
#include "../Ente.h"
#include "../ClassesAuxiliares/Listas/ListaEntidades.h"
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
    void imprimir();
    void executar(float dt = 0);
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
  virtual void gravaFase()= 0;
  virtual Fase* recFase() = 0;
  void limpaFase();
  void setJogando(bool n);
  void setGanhou(bool n);
  void setJogador(Jogador* j,int i = 1);
  void setMltplyr(bool m = false);
  void setBackground(int i = 3);
  ListaEntidades* getEntidades();
  const int getIBackground() const;
  bool getJogando();
  bool getGanhou();
  Jogador* getJogador(int i = 1);
  const bool getMltplyr() const ;
  GerenciadorColisoes* getGCol();
  virtual int getTipo() = 0;
  Spike* createSpike(float x = 0 , float y = 0);
  Jogador* createJogador(float x = 0, float y = 0);
  Chao* createChao(float x = 0, float y = 0);
  Tubo* createTubo(float x = 0, float y = 0);
  Projetil* createProjetil(float x = 0, float y = 0);
  Bandeira* createBandeira(float x = 0, float y = 0);
  Tartaruga* createTartaruga(float x = 0 , float y = 0);
};

}

using namespace Fases;