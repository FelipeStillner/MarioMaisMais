#include "Texto.h"
/*
Texto::Texto(const string t, int index, int x, int y, float fontsize)
{   
    //multiplicador do tamanho da fonte

    if(fontsize <= 0 || fontsize >= MAX)
    {
        fontsize = 1;
        std::cout << "erro em fontsize" << std::endl;
    }

    vTexto = t;
    int len = vTexto.size();
    for(int i = 0; i < len ; i++)
    {   
        int c = static_cast<int>(vTexto[i]);
        if (c == static_cast<int>('\n'))
        {
            y += fontsize * fontH;
        }
        else if((c!=(static_cast<int>(' '))))
        {
        c -= frstLt;
        sf::RectangleShape r = sf::RectangleShape (sf::Vector2(fontsize*fontW,fontsize*fontH));
        r.setTexture(text);
        r.setTextureRect(rSprite[c]);
        r.setPosition(x, y);
        rCaracteres.push_back(r);
        x+=fontsize*fontW;
        //r.setSize(sf::Vector2f(col.getWidth(), col.getHeight()));
        }
        else
        {
            x+=2*fontsize*fontW;
        }
    }
}

void Texto::imprimir(sf::RenderWindow* w)
{   
    sf::RenderWindow* rw = w;
    vector<sf::RectangleShape*>::iterator iT = rCaracteres.begin();
    while(iT != rCaracteres.end())
    {
        rw->draw(iT);
    }
}
Texto::~Texto()
{
    vector<sf::RectangleShape*>::iterator i= vCaracteres.begin();
    while(i != vCaracteres.end())
    {   sf::RectangleShape* pAux = (*i);
        i++;
        if(pAux){delete pAux;}
    }
    vCaracteres.clear();
}

void Texto::inicializarSprite()
{
    if((rSprite.empty()))
    {   
        int size = lstLtr-frstLtr + 1;
        int x =0;
        int y=0;
        for(int i=0;i<size;i++)
        {   
            sf::intRect r = sf::intRect (sf::Vector2 (fontWid,fontsize*fontH));
            r->setPosition(x, y);
            x += fontWid;
            rSprite.push_back(r);
        }
    }
}

void Texto::destroirSprite()
{
    vector<sf::RectangleShape*>::iterator i = vSprite.begin();
    while(i != vSprite.end())
    {   sf::RectangleShape* pAux = (*i);
        i++;
        if(pAux)
        {
            delete pAux;
        }
    }
    vSprite.clear();
}

void Texto::setGerenciadorGrafico(GerenciadorGrafico* gT)
{
    if(gT != NULL)
    {
        gText = gT;
    } 
    std::cout << "erro GG\n";
}
*/
