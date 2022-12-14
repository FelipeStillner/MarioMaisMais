#include "Fase1.h"

Fase1::Fase1() : Fase()
{
  background = (*gG)[3];
  mltply = false;

  createJogador(0.0, 0.0);
  createAndador(1000.0, 300.0);
  createAndador(1600.0, 300.0);
  srand(time(0));
  int n = rand() % 3 + 2;
  for (int i = 0; i < n; i++)
  {
    createAndador(3200.0 + i * 200, 300.0);
  }
  n = rand() % 3 + 2;
  for (int i = 0; i < n; i++)
  {
    createTartaruga(6000.0 + i * 200, 300.0);
  }
  createTartaruga(7400.0, 300.0);
  createTubo(1000.0, 600.0);
  createTubo(-1400.0, 400.0);
  createTubo(1600.0, 600.0);
  createTubo(2200.0, 600.0);
  createTubo(2800.0, 400.0);
  createTubo(3000.0, 600.0);
  createTubo(4500.0, 600.0);
  n = rand() % 3 + 2;
  for (int i = 0; i < n; i++)
  {
    createTubo(5000.0 + i * 200, 600.0 - i * 50);
  }
  createTubo(6900.0, 450.0);
  createTubo(7630.0, 400.0);
  createTubo(7750.0, 500.0);
  createTubo(8500, 650.0);
  createTubo(8650, 600.0);
  createTubo(8800, 550.0);
  createTubo(8950, 500.0);
  createTubo(9100, 450.0);
  createTubo(9250, 400.0);
  createTubo(9400, 350.0);
  createTubo(9550, 300.0);
  createTubo(9400, 650.0);
  createTubo(9550, 600.0);
  n = rand() % 2 + 1;
  for (int i = 0; i < n; i++)
  {
    createSpike(9870.0 + i * 80, 620.0);
  }
  createSpike(-1000.0, 620.0);
  createSpike(1900.0, 620.0);
  createSpike(2020.0, 620.0);
  createBandeira(10500.0, 0.0);
  createChao(-2000.0, 700.0);
  createChao(-1000.0, 700.0);
  createChao(0.0, 700.0);
  createChao(1000.0, 700.0);
  createChao(2000.0, 700.0);
  createChao(3000.0, 700.0);
  createChao(4000.0, 700.0);
  createChao(5000.0, 700.0);
  createChao(6000.0, 700.0);
  createChao(7000.0, 700.0);
  createChao(8000.0, 700.0);
  createChao(9000.0, 700.0);
  createChao(10000.0, 700.0);
}

Andador* Fase1::createAndador(float x, float y)
{
  Andador* pAux= new Andador(x, y, 1);
  entidades.push(pAux);
  gCol.incluir(static_cast<Inimigo*>(pAux));
  return(pAux);
}

void Fase1::gravaFase()
{
    std::ofstream arquivo;
    arquivo.open("Fases/Fase1.dat",std::ios::out);

    ListaEntidades* lista = this->getEntidades();
    int i ;

    arquivo<<static_cast<int>(this->getMltplyr());
    

    for(i=0;i<lista->size();i++)
    {
        Entidades::Entidade* pE = (*lista)[i];
        if(pE->getAtivo())
        {   arquivo<< std::endl
            << pE->getTipo()<<' '
            << pE->getX0()<<' '
            << pE->getY0()<<' '
            << pE->getX()<<' '
            << pE->getY()<<' '
            //arquivo<<pE->getVx()<<',';
            << pE->getVy();
        }
    }
    arquivo.close();
}
Fase* Fase1::recFase()
{
    int i ;
    std::ifstream arquivo;
    arquivo.open("Fases/Fase1.dat",std::ios::in);

    limpaFase();

    int tipo;

    bool mlt;

    float  X0, Y0 , X , Y , Vy ;

    arquivo>>mlt;

    setMltplyr(static_cast<bool>(mlt));

    while(!arquivo.eof())
    {   
        arquivo>>tipo>>X0>>Y0>>X>>Y>>Vy;
        Entidades::Entidade* pE = NULL;
        switch (tipo)
        {
        case PLAYER:
          pE=createJogador(X,Y);
          break;
        case ENEM1:
          pE=createAndador(X,Y);
          break;
        case ENEM2:
          pE=createTartaruga(X,Y);
          break;
        case TUBO:
          pE=createTubo(X,Y);
          break;
        case SPIK:
          pE=createSpike(X,Y);
          break;
        case CHAO:
          pE=createChao(X,Y);
          break;
        case BAND:
          pE=createBandeira(X,Y);
          break;
        case PROJ:
          pE=createProjetil(X,Y);
          break;
        default:
          break;
        }
        if(pE)
        {
          pE->setVy(Vy);
          pE->setX(X);
          pE->setY(Y);
          pE->setXX0(X0);
          pE->setYY0(Y0);
          pE->setAtivo(true);
        }
    }

    arquivo.close();

    return this;

}

Fase1::~Fase1()
{
  limpaFase();
  background=NULL;
}

int Fase1::getTipo()
{
  return FASE1;
}
