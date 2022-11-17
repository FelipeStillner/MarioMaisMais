#include "Fase.h"
#include "../Principal.h"

Fase::Fase() : Ente(), h(this), gCol(this)
{
  jogando = true;
  mltply= false;
  jog = NULL;
  jog2 = NULL;
  ganhou = false;
}

Fase::~Fase()
{
  
}

void Fase::executar(float dt)
{
  entidades.executar(dt);
  h.executar(dt);
}

void Fase::gerenciarColisoes()
{
  gCol.executar();
}

void Fase::imprimir()
{
  sf::RectangleShape r;
  sf::RenderWindow* w =gG->getWindow();
  r.setOrigin(- jog->getX() + (w->getSize().x/2) + 50, 100);
  r.setSize(sf::Vector2f(w->getSize().x + 100, w->getSize().y + 200));
  r.setTexture(background);
  w->draw(r);
  entidades.imprimir();
  h.imprimir();
}

ListaEntidades* Fase::getEntidades()
{
  return &entidades;
}

bool Fase::getJogando()
{
  return jogando;
}

void Fase::setJogando(bool n)
{
  jogando = n;
}

bool Fase::getGanhou()
{
  return ganhou;
}

void Fase::setGanhou(bool n)
{
  ganhou = n;
}

Jogador* Fase::getJogador(int i)
{
  if(i==1||!mltply)
  {
    return jog;
  }
  else
  {
    return jog2;
  }
}

void Fase::setJogador(Jogador* j,int i)
{ if(j)
  {
    if(!jog)
    {
      jog = j;
    }
    else if(!jog2 && getMltplyr())
    {
      jog2 = j;
    }
    else
    {
      std::cerr<<"ERRO EM SET JOGADOR"<<std::endl;
    }
  }
  /*
  if(i==1||!mltply){jog = j;}
  else if(i==2){jog2=j;}
  */
}

void Fase::setMltplyr(bool m)
{
  mltply = m;
}
const bool Fase::getMltplyr() const 
{
  return(mltply);
}

const int Fase::getIBackground() const
{
  return 3;
}

void Fase::setBackground(int i)
{
  background = (*gG)[i];
}

GerenciadorColisoes* Fase::getGCol()
{
  return &gCol;
}

Tubo* Fase::createTubo(float x , float y)
{
  Tubo* pAux = new Tubo(x, y);
  gCol.incluir(static_cast<Obstaculo*>(pAux));
  entidades.push(pAux);
  return(pAux);
}

Projetil* Fase::createProjetil(float x , float y)
{
  Projetil* pAux = new Projetil(x, y, 80, 80, 1);
  gCol.incluir(static_cast<Projetil*>(pAux));
  entidades.push(pAux);
  return(pAux);
}
Chao* Fase::createChao(float x , float y)
{
  Chao* pAux =  new Chao(x, y);
  gCol.incluir(static_cast<Obstaculo*>(pAux));
  entidades.push(pAux);
  return(pAux);
}

Jogador* Fase::createJogador(float x, float y)
{
  if(jog)
  {
    Luigi* pAux = new Luigi(x, y, 2);
    gCol.incluir(static_cast<Jogador*>(pAux));
    setJogador(static_cast<Jogador*>(pAux));
    entidades.push(pAux);
    return(pAux);
  }
  Jogador* pAux = new Jogador(x, y, 1000);
  gCol.incluir(static_cast<Jogador*>(pAux));
  setJogador(static_cast<Jogador*>(pAux));
  entidades.push(pAux);
  return(pAux);
}

Bandeira* Fase::createBandeira(float x , float y )
{
    Bandeira* pAux = new Bandeira(x, y);
    gCol.incluir(static_cast<Obstaculo*>(pAux));
    entidades.push(pAux);
    return(pAux);
}

void Fase::limpaFase()
{
  entidades.limpaLista();
  gCol.limpagCOL();
  jog=NULL;
  jog2=NULL;
}