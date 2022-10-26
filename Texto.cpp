#include "Texto.h"

    Texto::Texto(const string t =NULL, int index, int x, int y, float fontsize=1)
    {   
        //multiplicador do tamanho da fonte
        if(fontsize<=0||fontsize>=MAX){fontsize=1;cout<<"erro em fontsize"<<endl;}

        vTexto=t;
        len=vTexto.size();
        for(int i =0; i < len ; i++)
        {   
            int c = static_cast<int>(vTexto[i]);
            if (c==static_cast<int>('\n')){y+=fontsize*fontH;}
            else if((c!=(static_cast<int>(' '))))
            {
            c -=frstLt;
            sf::RectangleShape r = new sf::RectangleShape (sf::Vector2(fontsize*fontW,fontsize*fontH));
            r->setTexture(text);
            r->setTextureRect((rSprite[c]));
            r->setPosition(x, y);
            rCaracteres.push_back(r);
            x+=fontsize*fontW;
            //r.setSize(sf::Vector2f(col.getWidth(), col.getHeight()));
            }
            else{x+=2*fontsize*fontW;}
        }
    }
    virtual void Texto::imprimir(sf::RenderWindow* w)
    {   
        sf::RenderWindow* rw = w;
        vector<sf::RectangleShape*>::iterator iT = rCaracteres.begin();
        while(iT!=rCaracteres.end())
        {
            rw->draw((*iT));
        }
    }
    Texto::~Texto()
    {
        vector<sf::RectangleShape*>::iterator iT= vCaracteres.begin();
        while(it!= vCaracteres.end())
        {   sf::RectangleShape* pAux = (*iT);
            iT++;
            if(pAux){delete pAux;}
        }
        vCaracteres.clear();
    }
    static void Texto::inicializarSprite()
    {
        if((rSprite.empty()))
        {   
            int size = lstLtr-frstLtr + 1;
            int x =0;
            int y=0;
            for(int i=0;i<size;i++)
            {   
                sf::RectangleShape r = new sf::RectangleShape (sf::Vector2(sprW,fontsize*sprH));
                r->setPosition(x, y);
                x+=sprW;
                rSprite.push_back(r);
            }
        }
    }
    static void Texto::destroirSprite()
    {
        vector<sf::RectangleShape*>::iterator iT= vSprite.begin();
        while(it!= vSprite.end())
        {   sf::RectangleShape* pAux = (*iT);
            iT++;
            if(pAux){delete pAux;}
        }
            vSprite.clear();
    }
    static void setGerenciadorGrafico(const GerenciadorGrafico* gT){if(gT!=NULL){gText=gT;} cout<<"erro GG\n";}