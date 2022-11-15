#pragma once

#include "Afix.h"
#include "Ente.h"
#include "ClassesAuxiliares/ListaEntidades.h"
#include "Gerenciadores/GerenciadorColisoes.h"
#include"Entidades/Andador.h"
#include"Entidades/Chao.h"
#include"Entidades/Tubo.h"
#include"Entidades/Jogador.h"
#include"Entidades/Bandeira.h"

class Principal;

class Fase : public Ente
{
protected:
  GerenciadorColisoes gCol;
  sf::Texture* background;
  Principal* prin;
  ListaEntidades entidades;
  Jogador* jog;
  Jogador* jog2;
  bool jogando;
  bool mltply;
public:
  Fase(Principal *p=NULL);
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
  Entidade* create(int i = 0, float x = 0, float y = 0);
  Jogador* createJogador(float x = 0, float y = 0);
  Chao* createChao(float x = 0, float y = 0);
  Tubo* createTubo(float x = 0, float y = 0);
  Bandeira* createBandeira(float x = 0, float y = 0);
  void setBackground(int i = 3);
  const int getIBackground() const;
  virtual void gravaFase()= 0;
  virtual Fase* recFase() = 0;
  GerenciadorColisoes* getGCol();
};
