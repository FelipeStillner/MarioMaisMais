#pragma once

#include "Entidade/Entidade.h"

#include "Afix.h"
#include "Ente.h"
using std::string;
using std::list;
using std::vector:



class Texto : public Ente
{   
    private:
    string vTexto;
    //int iSprite;
    static vector<sf::RectangleShape*> rSprite;
    vector<sf::RectangleShape*> rCaracteres;
    int pX; int pY;
    static GerenciadorGrafico * gText;
    static int fontWid;
    static int fontH;
    static int frstLt;
    static int lstLt;
    sf::Texture* textura;

    public:

    Texto(const string t =NULL, int index, int x, int y, int fontsize);
    ~Texto();
    virtual void imprimir(sf::RenderWindow* w);
    static void inicializarSprite();
    static void destroirSprite();
    static void setGerenciadorGrafico(GerenciadorGrafico* gT);
    
}