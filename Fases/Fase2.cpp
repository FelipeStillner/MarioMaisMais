#include "Fase2.h"

Fase2::Fase2() : Fase()
{
  srand(time(0));
  int i, n;
  background = (*gG)[3];
  mltply = false;

  createJogador(500.0, 0.0);

  createLancador(2300.0, 0.0);
  n = rand() % 2;
  for (i = 0; i < n + 3; i++)
  {
    createLancador(5500 + i * 500, 0.0);
    createTubo(5460.0 + i * 500, 620.0 - i * 100);
    createMola(5300.0 + i * 500, 0.0);
  }

  createTartaruga(1400.0, 400.0);
  createTartaruga(-1000.0, 400.0);


  createSpike(1280, 620);
  createSpike(1440, 620);
  n = rand() % 3+1;
  for (i = 0; i < n ; i++)
  {
    createSpike(4560 + i * 80, 630.0);
  }
  createTubo(4560 + (i+1) * 80, 600);

  createBandeira(11000.0, 0.0);
  createBandeira(-2000.0, 0.0);

  createMola(-500.0, 0.0);
  n = rand() % 2;
  for (i = 0; i < n + 5; i++)
  {
    createMola(2840 + i * 160, 650.0);
  }
  createMola(4400.0, 0.0);

  for (i = 0; i < n + 1; i++)
  {
    createTartaruga(2900 + i * 200, 200.0);
  }

  createTubo(2540, 300.0);
  createTubo(2840 + (n+5) * 160, 400.0);
  createTubo(4000, 500.0);
  createTubo(-1400.0, 400.0);
  createTubo(1000.0, 600.0);
  createTubo(1600.0, 600.0);
  createTubo(2200, 500);
  createTubo(8800, 500);
  createTubo(9000, 400);
  createTubo(10500, 600);

  createChao(-3000.0, 700.0);
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
  createChao(11000.0, 700.0);

  createBowser(10000.0, 200.0);
}

Fase2::~Fase2()
{
  background=NULL;
  limpaFase();
}

Bowser* Fase2::createBowser(float x, float y)
{
    Bowser* pAux = new Bowser(this, x, y, 20);
    gCol.incluir(static_cast<Inimigo*>(pAux));
    entidades.push(pAux);
    return(pAux);
}

Lancador* Fase2::createLancador(float x, float y)
{
    Lancador* pAux= new Lancador(this, x, y, 1);
    gCol.incluir(static_cast<Inimigo*>(pAux));
    entidades.push(pAux);
    return(pAux);
}

Mola* Fase2::createMola(float x , float y )
{
    Mola* pAux = new Mola(x, y, Vel);
    gCol.incluir(static_cast<Obstaculo*>(pAux));
    entidades.push(pAux);
    return(pAux);
}

void Fase2::gravaFase()
{
    std::ofstream arquivo;
    arquivo.open("Fases/Fase2.dat",std::ios::out);

    ListaEntidades* lista = this->getEntidades();
    int i ;

    arquivo<<static_cast<int>(this->getMltplyr());

    for(i=0;i<lista->size();i++)
    {
        Entidades::Entidade* pE = (*lista)[i];
        if(pE->getAtivo())
        {
            arquivo<< std::endl
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

Fase* Fase2::recFase()
{
      int i ;
    std::ifstream arquivo;
    arquivo.open("Fases/Fase2.dat",std::ios::in);

    Fase2* pFase = new Fase2();

    std::cout<<"REC FASE"<<std::endl;

    int tipo;

    bool mlt;

    float  X0, Y0 , X , Y , Vy ;

    arquivo>>mlt;

    std::cout<<mlt<<std::endl;

    pFase->setMltplyr(static_cast<bool>(mlt));

    while(!arquivo.eof())
    {   
        arquivo>>tipo>>X0>>Y0>>X>>Y>>Vy;
        Entidades::Entidade* pE = NULL;
        switch (tipo)
        {
        case PLAYER:
          pE=pFase->createJogador(X,Y);
          break;
        case ENEM2:
          pE=pFase->createLancador(X,Y);
          break;
        case ENEM3:
          pE=pFase->createTartaruga(X,Y);
          break;
        case MOLA:
          pE=pFase->createMola(X,Y);
          break;
        case SPIK:
          pE=pFase->createSpike(X,Y);
          break;
        case TUBO:
          pE=pFase->createTubo(X,Y);
          break;
        case CHAO:
          pE=pFase->createChao(X,Y);
          break;
        case BAND:
          pE=pFase->createBandeira(X,Y);
          break;
        case PROJ:
          pE=pFase->createProjetil(X,Y);
          break;
        case BOSS:
          pE=pFase->createBowser(X,Y);
          break;
        default:
          break;
        }
        std::cout<<tipo<<X0<<Y0<<X<<Y<<Vy<<std::endl;
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

    std::cout<<"Retornou"<<std::endl;
    return pFase;
}

int Fase2::getTipo()
{
  return FASE2;
}
