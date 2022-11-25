#include "Fase.h"
#include "../Principal.h"

Fase::Fase() : Ente(), h(this), gCol()
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
      std::cout<<"ERRO EM SET JOGADOR"<<std::endl;
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
Tartaruga* Fase::createTartaruga(float x, float y)
{
    Tartaruga* pAux= new Tartaruga(x, y, 2);
    gCol.incluir(static_cast<Inimigo*>(pAux));
    entidades.push(pAux);
    return(pAux);
}

Jogador* Fase::createJogador(float x, float y)
{
  if(jog)
  {
    Luigi* pAux = new Luigi(x, y, 5);
    gCol.incluir(static_cast<Jogador*>(pAux));
    setJogador(static_cast<Jogador*>(pAux));
    entidades.push(pAux);
    return(pAux);
  }
  Jogador* pAux = new Jogador(x, y, 5);
  gCol.incluir(static_cast<Jogador*>(pAux));
  setJogador(static_cast<Jogador*>(pAux));
  entidades.push(pAux);
  return(pAux);
}

Bandeira* Fase::createBandeira(float x , float y )
{
    Bandeira* pAux = new Bandeira(this, x, y);
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

Spike* Fase::createSpike(float x , float y )
{
    Spike* pAux = new Spike(x, y, 1);
    gCol.incluir(static_cast<Obstaculo*>(pAux));
    entidades.push(pAux);
    return(pAux);
}

Fase::Hud::Hud(Fase* f)
{
  this->f = f;
}

Fase::Hud::~Hud()
{
}

void Fase::Hud::imprimir()
{
  int x = -gG->getWindow()->getView().getCenter().x - gG->getWindow()->getSize().x/2 + 100,
    y = -gG->getWindow()->getView().getCenter().y - gG->getWindow()->getSize().y/2;
  sf::RectangleShape r;
  r.setTexture((*gG)[16]);
  r.setOrigin(x, 0);
  r.setSize(sf::Vector2f(80, 80));
  for (int i = 0; i < f->getJogador(1)->getVida(); i++)
  {
    r.setOrigin(x, 0);
    gG->getWindow()->draw(r);
    x += 100;
  }

  Botao b1(sf::Vector2f(-400, -200),std::to_string(f->getJogador(1)->getPont()));
  b1.imprimir();
  
  if (f->getMltplyr())
  {
    r.setTexture((*gG)[17]);
    x = -gG->getWindow()->getView().getCenter().x - gG->getWindow()->getSize().x/2 + 100;
    r.setSize(sf::Vector2f(80, 80));
    for (int i = 0; i < f->getJogador(2)->getVida(); i++)
    {
      r.setOrigin(x, -100);
      gG->getWindow()->draw(r);
      x += 100;
    }

    Botao b2(sf::Vector2f(-400, -100),std::to_string(f->getJogador(2)->getPont()));
    b2.imprimir();
  }

}

void Fase::Hud::executar(float dt)
{
}