#include "Fase1.h"
#include "Principal.h"

Fase1::Fase1(Principal* prin) : Fase(prin)
{
  GerenciadorGrafico* g = prin->getGerenciadorGrafico();
  background = (*g)[3];
  jog = new Jogador(prin, 500.0, 500.0, 160, 320, (*g)[0], Colisao(10, 10, 140, 300), 200,Animacao(sf::IntRect(0, 0, 16, 32), 0.25, "1232"));
  entidades.push(jog);
  gCol.incluir(jog);
  Projetil* p = new Projetil(0, 0, 80, 80, (*g)[1], Colisao(10, 10, 60, 60), 200.0, 100.0, 1);
  entidades.push(p);
  gCol.incluir(p);
  Obstaculo* o1 = new Obstaculo(1000.0, 800.0, 320, 320, (*g)[2], Colisao(10, 10, 300, 300));
  entidades.push(o1);
  gCol.incluir(o1);
  Obstaculo* o2 = new Obstaculo(0.0, 900.0, 1920, 320, (*g)[5], Colisao(10, 10, 1900, 300));
  entidades.push(o2);
  gCol.incluir(o2);
  Inimigo* i = new Inimigo(1000.0, 600.0, 160, 160, (*g)[4], Colisao(10, 10, 140, 140), 1,Animacao(sf::IntRect(0, 0, 16, 16), 0.25, "12"));
  entidades.push(i);
  gCol.incluir(i);
}

Fase1::~Fase1()
{
}