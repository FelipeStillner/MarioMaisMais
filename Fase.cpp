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
      { pAux = new Jogador(x, y, 160, 320, 0, Colisao(10, 10, 140, 300), 200,Animacao(sf::IntRect(0, 0, 16, 32), 0.25, "1232"));
        gCol.incluir(static_cast<Jogador*>(pAux));
        setJogador(static_cast<Jogador*>(pAux));
      }
      break;
    case ENEM1:
       { pAux= new Inimigo(x, y, 160, 160, 4, Colisao(10, 10, 140, 140), 1,Animacao(sf::IntRect(0, 0, 16, 16), 0.25, "12"));
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
        {pAux =  new Obstaculo(x, y, 320, 320, 2, Colisao(10, 10, 300, 300));
          gCol.incluir(static_cast<Obstaculo*>(pAux));
        }
      break;
    case OBS2:
        {pAux = new Obstaculo(x, y, 1920, 320, 5, Colisao(10, 10, 1900, 300));
          gCol.incluir(static_cast<Obstaculo*>(pAux));
        }
      break;
    case PROJ:
        {pAux = new Projetil(x, y, 80, 80, 1, Colisao(10, 10, 60, 60), 200.0, 100.0, 1);
          gCol.incluir(static_cast<Projetil*>(pAux));
        }

      break;
    
    default:
      break;
    }
    entidades.push(pAux);
  }

const int Fase::getIBackground() const
{
  return 3;
}
void Fase::setBackground(int i)
{
  background=(*gG)[3];
}