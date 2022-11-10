#include "Fase.h"
#include "Principal.h"
#include "Entidades/Jogador.h"

Fase::Fase(Principal* p) : Ente()
{
  prin = p;
  jogando = true;
  mltply= false;
  jog = NULL;
  jog2 = NULL;
}

Fase::~Fase()
{
  
}

void Fase::executar(float dt)
{
  entidades.executar(dt);
}

void Fase::gerenciarColisoes()
{
  gCol.executar();
}

void Fase::imprimir()
{
  sf::RectangleShape r;
  sf::RenderWindow* w =gG->getWindow();
  r.setOrigin(- jog->getX() + (w->getSize().x/2),0);
  r.setSize(sf::Vector2f(w->getSize().x, w->getSize().y));
  r.setTexture(background);
  w->draw(r);
  entidades.imprimir();
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

Jogador* Fase::getJogador(int i)
{
  if(i==1||!mltply){return jog;}
  else if(i==2){return jog2;}
  
}

void Fase::setJogador(Jogador* j,int i)
{ if(j)
  {
    if(!jog){jog=j;}
    else if(!jog2 && getMltplyr()){jog2=j;}
    else{std::cerr<<"ERRO EM SET JOGADOR"<<std::endl;}
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
  Entidade* Fase::create(int i, float x, float y )
  { 
    //é um "factory method"!
    Entidade* pAux= NULL;
    switch (i)
    {
    case PLAYER:
      { 
        pAux = new Jogador(x, y, 200);
        gCol.incluir(static_cast<Jogador*>(pAux));
        setJogador(static_cast<Jogador*>(pAux));
      }
      break;
    case ENEM1:
       { 
        pAux= new Inimigo(x, y, 200);
        gCol.incluir(static_cast<Inimigo*>(pAux));
       }
      break;
    case ENEM2:

      break;
    case ENEM3:

      break;
    case BOSS:

      break;
    case OBS1:
        {
          pAux =  new Tubo(x, y);
          gCol.incluir(static_cast<Obstaculo*>(pAux));
        }
      break;
    case OBS2:
        {
          pAux = new Chao(x, y);
          gCol.incluir(static_cast<Obstaculo*>(pAux));
        }
      break;
    case PROJ:
        {pAux = new Projetil(x, y, 80, 80, 1);
          gCol.incluir(static_cast<Projetil*>(pAux));
        }

      break;
    
    default:
      break;
    }
    entidades.push(pAux);
    return(pAux);
  }

const int Fase::getIBackground() const
{
  return 3;
}
void Fase::setBackground(int i)
{
  background=(*gG)[i];
}