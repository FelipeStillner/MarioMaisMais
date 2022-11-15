#include"Botao.h"
 Botao::Botao(sf::Keyboard::Key o, sf::Vector2f p , string t): texto(t)
 {

    //texto+t;
    pos.x = p.x;
    pos.y =p.y;
    opt = o;
 }
void Botao::executar(float dt )
{
    imprimir();
}
void Botao::imprimir()
{
    escreveTexto();
}
 Botao::~Botao()
 {

 }
 void Botao::escreveTexto()
{   
    sf::RenderWindow * w = gG->getWindow();
    float len = 8.0;
    int i,j;
    float wd = 8.0 , hg = 8.0;
    float x = pos.x + w->getView().getCenter().x - 200, y =pos.y + w->getView().getCenter().y - 200;

    sf::Texture* text = (*gG)[8];
   
  
    for(i=0;i<(texto).size();i++)
    {
        int lAux =  static_cast<int>(texto[i]);
        if(lAux!=' '&& lAux!='\0')
        {   
            sf::RectangleShape rAux;
            rAux.setTexture(text);
            rAux.setTextureRect(*((*letras)[lAux-'!']));
            rAux.setPosition(len*8.0*(i)+x, y);
            rAux.setSize(sf::Vector2f(8*wd, 8*hg));
            w->draw(rAux);
        }
    }
}

void Botao::inicializaLetras() 
{   
    letras = new vector <sf::IntRect*> ;
    int i ;
    if((*letras).empty())
    {
        for(i=0;i<('~'-'!'+1);i++)
        {
            (*letras).push_back(new sf::IntRect(i*8,0,8,8));
        }
    }
}

void Botao::destroiLetras()
{
    int i =0 ;
    while(i<('~'-'!'+1))
    {
        sf::IntRect * pAux = (*letras)[i];
        i++;
        delete pAux;
    }
    (*letras).clear();
}

const sf::Keyboard::Key Botao::getOpt() const
{
    return(opt);
}
vector<sf::IntRect*>* Botao::letras = NULL;