#include "Fase1.h"

Fase1::Fase1(Principal* prin) : Fase(prin)
{
  background = (*gG)[3];
  mltply = true;

  create(PLAYER, 400.0, 200.0);
  create(PLAYER, 500.0, 200.0);
  create(ENEM1, 1000.0, 300.0);
  create(TUBO, 1000.0, 600.0);
  create(CHAO, 0.0, 700.0);
}
Andador* Fase1::createAndador(float x, float y)
{
  Andador* pAux= new Andador(x, y, 200);
  entidades.push(pAux);
  gCol.incluir(static_cast<Inimigo*>(pAux));
  return(pAux);
}

void Fase1::gravaFase()
{
    std::ofstream arquivo;
    arquivo.open("Fase1.dat",std::ios::out);

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
Fase* Fase1::recFase()
{
      int i ;
    std::ifstream arquivo;
    arquivo.open("Gerenciadores/novoarquivo1.dat",std::ios::in);

    Fase1* pFase = new Fase1();

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
        case ENEM1:
          pE=pFase->createAndador(X,Y);
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

Fase1::~Fase1()
{

}