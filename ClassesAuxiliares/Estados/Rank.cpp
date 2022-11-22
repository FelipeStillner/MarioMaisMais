#include "Rank.h"

Rank::Rank():botoes(),mapa(),back(sf::Vector2f(0,3*8.0*8.0),"1)BACK")
{

}
Rank::~Rank()
{
    limpaBotoes();
    mapa.clear();
}
void Rank::imprimir()
{   int i;
    for( i=0;i < botoes.size(); i++)
    {
        botoes[i]->imprimir();
    }
    back.imprimir();
}
Estado *Rank::eExecutar()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
    {
        return (eInicial);
    }
    else
    {
        return (this);
    }
}
Fase *Rank::getFase() const
{
    return NULL;
}
void Rank::setFase(int i )
{
    pFase = NULL;
}
void Rank::executar(const float dt )
{   
    std::ifstream arquivo;
    mapa.clear();
    limpaBotoes();
    arquivo.open("ClassesAuxiliares/Estados/Rank.dat",std::ios::in);
    int n = 0;
    char ch[10];
    int pt , i;
    int ps[2][3];
    
    while (!arquivo.eof())
    {   
        arquivo>>ch>>pt;
        std::cout<<ch<<pt<<std::endl;
        if(strcmp(ch,"")&&pt>=0)
        {mapa.insert(mPar(pt,string(ch)));}
        else
        {std::cerr<<"ERRO EM MAPA"<<std::endl;}
    }
    arquivo.close();

    mMapa::iterator it = mapa.begin();
    i = 0;
    for(it=mapa.begin();it!=mapa.end()&&i<3;it++)
    {
        botoes.push_back(new Botao(sf::Vector2f(0,i*8.0*8.0), (*it).second ));
        botoes.push_back(new Botao(sf::Vector2f((10)*8.0*8.0,i*8.0*8.0), string(std::to_string(static_cast<int>((*it).first))) ));
        i++;
    }
}
void Rank::limpaBotoes()
{   
    vector<Botao*>::iterator it =botoes.begin();
    while(it!=botoes.end())
    {
        Botao* pAux =(*it);
        it++;
        delete pAux;
    }
    botoes.clear();
}