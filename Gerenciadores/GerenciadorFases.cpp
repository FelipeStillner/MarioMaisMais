#include "GerenciadorFases.h"

GerenciadorFases::GerenciadorFases()
{

}
GerenciadorFases::~GerenciadorFases()
{

}
Fase* GerenciadorFases::recFase()
{   
    int i ;
    std::ifstream arquivo;
    arquivo.open("Gerenciadores/novoarquivo.dat",ios::in);

    //Fase* pFase = new Fase();
    Fase* pFase = new Fase(pP);

    int tipo;

    float  X0, Y0 , X , Y , Vy ;

    arquivo>>tipo;

    pFase->setBackground(tipo);

    while(!arquivo.eof())
    {   
        arquivo>>tipo>>X0>>Y0>>X>>Y>>Vy;
        Entidade* pE = pFase->create(tipo,X,Y);
        pE->setVy(Vy);
        //pE->setX(X);
        //pE->setY(Y);
        pE->setXX0(X0);
        pE->setYY0(Y0);
        //pE->setAtivo(true);
    }

    arquivo.close();

}
void GerenciadorFases::gravaFase(Fase* f = NULL)
{
    std::ofstream arquivo;
    arquivo.open("Gerenciadores/novoarquivo.dat",ios::out);

    ListaEntidades* lista = f->getEntidades();
    int i ;

        arquivo<<f->getIBackground()<<std::endl;
    for(i=0;i<lista->size();i++)
    {
        Entidade* pE = (*lista)[i];
        if(true)
        {
            //arquivo<<pE->getAtivo()<<',';
            //arquivo<<(pE->getColisao()).getHeight()<<',';
            //arquivo<<(pE->getColisao()).getWidth()<<',';
            //arquivo<<(pE->getColisao()).getX()<<',';
            //arquivo<<(pE->getColisao()).getY()<<',';

            arquivo<<pE->getX0()<<' ';
            arquivo<<pE->getY0()<<' ';
            arquivo<<pE->getX()<<' ';
            arquivo<<pE->getY()<<' '; 
            //arquivo<<pE->getVx()<<',';
            arquivo<<pE->getVy()<<' ';
            arquivo<<std::endl;
        }
    }
    arquivo.close();
}

Fase* GerenciadorFases::getFase(int i )
{   
    Fase* pauxF = NULL;
    if(i==1){pauxF = new Fase1(pP);}

    fase= pauxF;
    return (pauxF);
}