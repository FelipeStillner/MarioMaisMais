#include"Menu.h"

/*
    Bom dia

    Jogar
        n jogadores? 1 ou 2
        
        Fases? Mapas?




    Opcoes

    Ranking


*/

void Menu::setgT(GerenciadorGrafico * gT)
{
    gText = *gT;
}
Menu::Menu(/*GerenciadorGrafico * gT*/) : Ente()
{   
    //gText = *gT;
    int frstL= '!';
    int i,j;
    //strcpy(strings[0],"MARIO");
    char * nstring = new char;
    strcpy(nstring,"MARIO");
    strings.push_back(nstring);
    //strings[1]+="++";
    for(i=0;i<('~'-'!'+1);i++)
    {
        letras.push_back(new sf::IntRect(i*8,0,8,8));
    }




}

Menu::~Menu()
{
    
    int i =0 ;
    while(i<('~'-'!'+1))
    {
        sf::IntRect * pAux = letras[i];
        i++;
        delete pAux;
    }
        letras.clear();


}

void Menu::executar(float dt)
{

}

void Menu::imprimir /*const*/ (sf::RenderWindow* w)
{
    int i,j;
    float wd = 8.0 , hg = 8.0;
    float x = 500.0, y = 500.0;
    sf::Texture* text = gText[8];

    for(j=0;j<strings.size();j++)
    for(i=0;i<(strings[j]).size();i++)
    {
        int lAux =  strings[j][i];
        if(lAux!=' ')
        {
            sf::RectangleShape rAux;
            rAux.setTexture(text);
            rAux.setTextureRect(*(letras[lAux-'!']));
            rAux.setPosition(8*8.0*i+x, y+8*8.0*j);
            rAux.setSize(sf::Vector2f(8*wd, 8*hg));
            w->draw(rAux);
        }
    }
}



    /*
    vTexto = texto a ser escrito
    fIndex = indice da textura
    fX = posicao x da primeira letra
    fY = posicao y da primeria letra
    fSize = tamanho da fonte
    */
/*
void Menu::escreveTexto(string vTexto, int fIndex, int fX , int fY, int fSize)
{
    int len = vTexto.size();
    int i =0;
    for(i=0;i<len;i++)
    {
        
    }
}
*/