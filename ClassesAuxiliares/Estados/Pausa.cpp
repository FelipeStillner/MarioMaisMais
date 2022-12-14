#include"Pausa.h"
Pausa::Pausa () :
resume(sf::Vector2f(0,0),string("ESC)RESUME")),
save(sf::Vector2f(0,8.0*8.0),string("1)SAVE")),
quit(sf::Vector2f(0,8.0*8.0*2),string("2)QUIT"))
{

}

Pausa::~Pausa ()
{

}

void Pausa ::imprimir()
{
    resume.escreveTexto();
    save.escreveTexto();
    quit.escreveTexto();
}

Estado* Pausa::eExecutar()
{   
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        return (this);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
    {
        pFase->gravaFase();
        (static_cast<Save*>(eSave))->limpaSave();
        return (eSave);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
    {   
        Fase* pAux = pFase;
        pFase = NULL;
        delete pAux;
        return(eInicial);
    }
    else
    {
        return (this);
    }
}
void  Pausa::setFase(const int i)
{   
    if(i == 1)
    {
        pFase = new Fase1();
    }
    else if(i == 2)
    {

        pFase = new Fase2();
    }
    
}
Fase* Pausa::getFase() const
{
    return(pFase);
}


void Pausa::salvarPontuacao()
{
    int p1 = pFase->getJogador(1)->getPont();
    std::ofstream arquivo;
    arquivo.open("ClassesAuxiliares/Estados/Rank.dat",std::ios::app);
    char nome1[10];
    std::cin>>nome1;
    arquivo<<std::endl;
    arquivo<<nome1<<' '<<p1;
    if(pFase->getMltplyr())
    {   
        int p2 = pFase->getJogador(2)->getPont();
        char nome2[10];
        arquivo<<std::endl;
        std::cin>>nome2;
        arquivo<<nome2<<' '<<p2;
    }
    arquivo.close();
}   