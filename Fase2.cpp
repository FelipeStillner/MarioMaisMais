#include "Fase2.h"

Fase2::Fase2(Principal* prin) : Fase(prin)
{
  background = (*gG)[3];
  mltply = true;

  create(PLAYER, 1000.0, 200.0);
  create(PLAYER, 500.0, 200.0);
  //create(ENEM1, 2000.0, 400.0);
  create(ENEM2, 2400.0, 300.0);
  create(ENEM3, 1400.0, 400.0);
  create(MOLA, 800.0, 0.0);
  create(TUBO, 1000.0, 600.0);
  create(SPIK, 0, 400);
  create(BAND, 2800.0, 0.0);
  create(TUBO, 1600.0, 600.0);
  create(TUBO, 2200.0, 600.0);
  create(CHAO, 0.0, 700.0);
  create(CHAO, 1800.0, 700.0);
}

Tartaruga* Fase2::createTartaruga(float x, float y)
{
    Tartaruga* pAux= new Tartaruga(x, y, 2);
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
    Mola* pAux = new Mola(x, y, 31);
    gCol.incluir(static_cast<Obstaculo*>(pAux));
    entidades.push(pAux);
    return(pAux);
}
Spike* Fase2::createSpike(float x , float y )
{
    Spike* pAux = new Spike(x, y, 1);
    gCol.incluir(static_cast<Obstaculo*>(pAux));
    entidades.push(pAux);
    return(pAux);
}

Fase2::~Fase2()
{
}
void Fase2::gravaFase()
{
    std::ofstream arquivo;
    arquivo.open("Fase2.dat",std::ios::out);

    ListaEntidades* lista = this->getEntidades();
    int i ;

    arquivo<<static_cast<int>(this->getMltplyr())<<std::endl;

    for(i=0;i<lista->size();i++)
    {
        Entidades::Entidade* pE = (*lista)[i];
        if(pE->getAtivo())
        {
            arquivo << pE->getTipo()<<' ';
            arquivo << pE->getX0()<<' ';
            arquivo << pE->getY0()<<' ';
            arquivo << pE->getX()<<' ';
            arquivo << pE->getY()<<' '; 
            //arquivo<<pE->getVx()<<',';
            arquivo << pE->getVy()<<' ';
            arquivo << std::endl;
        }
    }
    arquivo.close();
}
Fase* Fase2::recFase()
{
      int i ;
    std::ifstream arquivo;
    arquivo.open("Gerenciadores/novoarquivo1.dat",std::ios::in);

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