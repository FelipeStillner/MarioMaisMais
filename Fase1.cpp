#include "Fase1.h"
#include "Principal.h"

Fase1::Fase1(Principal* p) : Fase(p)
{
  GerenciadorGrafico* g = p->getGerenciadorGrafico();
  background = (*g)[3];
  entidades.setJogador(new Jogador(p, 500.0, 500.0, 160, 320, (*g)[0], Colisao(10, 10, 140, 300), 1,Animacao(sf::IntRect(0, 0, 16, 32), 0.25, "1232")));
  entidades.push(new Projetil(0, 0, 80, 80, (*g)[1], Colisao(10, 10, 60, 60), 200.0, 100.0, 0));
  entidades.push(new Obstaculo(1000.0, 800.0, 320, 320, (*g)[2], Colisao(10, 10, 300, 300)));
  entidades.push(new Obstaculo(0.0, 900.0, 1920, 320, (*g)[5], Colisao(10, 10, 1900, 300)));
  entidades.push(new Inimigo(1000.0, 600.0, 160, 160, (*g)[4], Colisao(10, 10, 140, 140), 1,Animacao(sf::IntRect(0, 0, 16, 16), 0.25, "12")));
}

Fase1::~Fase1()
{
}