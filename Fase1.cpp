#include "Fase1.h"
#include "Principal.h"

Fase1::Fase1(Principal* prin) : Fase(prin)
{
  background = (*gG)[3];
  mltply = true;
  
  

  /*
  jog = new Jogador(prin, 400.0, 400.0, 160, 320, 0, Colisao(10, 10, 140, 300), 200,Animacao(sf::IntRect(0, 0, 16, 32), 0.25, "1232"));
  entidades.push(jog);
  gCol.incluir(jog);
  jog2 = new Jogador(prin, 500.0, 400.0, 160, 320, 0, Colisao(10, 10, 140, 300), 200,Animacao(sf::IntRect(0, 0, 16, 32), 0.25, "1232"));
  entidades.push(jog2);
  gCol.incluir(jog2);
  mltply = true;
  Projetil* p = new Projetil(0, 0, 80, 80, 1, Colisao(10, 10, 60, 60), 200.0, 100.0, 1);
  entidades.push(p);
  gCol.incluir(p);
  Obstaculo* o1 = new Obstaculo(1000.0, 800.0, 320, 320, 2, Colisao(10, 10, 300, 300));
  entidades.push(o1);
  gCol.incluir(o1);
  Obstaculo* o2 = new Obstaculo(0.0, 900.0, 1920, 320, 5, Colisao(10, 10, 1900, 300));
  entidades.push(o2);
  gCol.incluir(o2);
  Inimigo* i = new Inimigo(1000.0, 600.0, 160, 160, 4, Colisao(10, 10, 140, 140), 1,Animacao(sf::IntRect(0, 0, 16, 16), 0.25, "12"));
  entidades.push(i);
  gCol.incluir(i);*/

  create(PLAYER,400.0, 400.0);
  create(PLAYER,500.0, 400.0);
  create(ENEM1,1000.0, 600.0);
  create(OBS1,1000.0, 800.0);
  create(OBS2,0.0, 900.0);

}

Fase1::~Fase1()
{

}