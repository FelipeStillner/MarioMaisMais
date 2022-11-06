#include"Menu.h"

/*
    Bom dia

    Jogar
        n jogadores? 1 ou 2
        
        Fases? Mapas?




    Opcoes

    Ranking


*/


Menu::Menu(int k) : Ente()
{   
    setPausa(true);
    int frstL= '!';
    int i,j;
    //strcpy(strings[0],"MARIO");

    //strings[1]+="++";
    
    char * nstring = new char;
    strcpy(nstring,"mario");
    strings.push_back(nstring);
    strcpy(nstring,"PLAY");
    strings.push_back(nstring);
    strcpy(nstring,"RANK");
    strings.push_back(nstring);
    
   
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

void Menu::imprimir ()
{   
    int i,j;
    float wd = 8.0 , hg = 8.0;
    float x = 100.0, y = 100.0;
    sf::Texture* text = (*gG)[8];
    sf::RenderWindow * w = gG->getWindow();
    float len = 8.0;
    for(j=0;j<strings.size();j++)
    {
    for(i=0;i<(strings[j]).size();i++)
    {
        int lAux =  static_cast<int>(strings[j][i]);
        if(lAux!=' '&& lAux!='\0')
        {   
            sf::RectangleShape rAux;
            rAux.setTexture(text);
            rAux.setTextureRect(*(letras[lAux-'!']));
            rAux.setPosition(len*8.0*(i)+x, y+len*8.0*j);
            rAux.setSize(sf::Vector2f(8*wd, 8*hg));
            w->draw(rAux);
            
        }
    }
    }
}

void Menu::setPausa(bool p)
{
    pausado = p;
}
const bool Menu::getPausa() const
{
    return(pausado);
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