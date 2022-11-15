#include "Menu.h"

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
    int frstL = '!';
    int i, j;
    setEstado(INICIAL);
    Botao::inicializaLetras();

    // Estado::pMenu = this;

    Estado::eInicial= new Inicial;
    Estado::ePlay= new Play;
    Estado::eLoad= new Load;
    pEstado = Estado::eInicial;

    // strcpy(strings[0],"MARIO");

    // strings[1]+="++";

    /*
    char * nstring = new char;
    strcpy(nstring,"mario++");
    strings.push_back(nstring);
    strcpy(nstring,"PLAY");
    strings.push_back(nstring);
    strcpy(nstring,"RANK");
    strings.push_back(nstring);
    */
    /*
     for(i=0;i<('~'-'!'+1);i++)
     {
         //letras.push_back(new sf::IntRect(i*8,0,8,8));
     }*/
}

Menu::~Menu()
{
    /*
    int i =0 ;
    while(i<('~'-'!'+1))
    {
        sf::IntRect * pAux = letras[i];
        i++;
        delete pAux;
    }
        letras.clear();

    */
}

void Menu::executar(float dt)
{
    //imprimir();
    sf::Event event;
    sf::RenderWindow *rw = (gG->getWindow());
    // rw->mou
    rw->pollEvent(event);

    sf::sleep(sf::seconds(1));
    pEstado=pEstado->executar();

    // pEstado=pEstado->executar();

    /*
    switch (estado)
    {
    case INICIAL:
        {

        }
        break;
    case PAUSA:

        break;
    case LOAD:

        break;
    case RANK:
        {

        }
        break;
    case EXIT:
        {
            (gG->getWindow())->close();
        }
        break;
    default:
        break;
    }
    */
}
void Menu::mouseClick(sf::Vector2<float> vMouse)
{
    float xw = getgG()->getWindow()->getPosition().x;
    float yw = getgG()->getWindow()->getPosition().y;
    switch (estado)
    {
    case INICIAL:
        {
            if (vMouse.x >= xw && vMouse.x <= ((8.0 * 8.0 * 4) + xw))
            {
                if (vMouse.y >= (8.0 * 8.0 + yw) && vMouse.y <= ((8.0 * 8.0) * 2 + yw))
                {
                    setEstado(PLAY);
                }
                else if ((vMouse.y >= ((8.0 * 8.0) * 2 + yw)) && (vMouse.y <= ((8.0 * 8.0) * 3 + yw)))
                {
                    setEstado(RANK);
                }
                else if ((vMouse.y >= ((8.0 * 8.0) * 3 + yw)) && (vMouse.y <= ((8.0 * 8.0) * 4 + yw)))
                {
                    setEstado(QUITGAME);
                }
            }
        }
        break;
    case PLAY:
        {
            // menu de carregamento
        }
        break;
    case PAUSA:
        {
        }
        break;
    case LOAD:
        {
        }
        break;
    case RANK:
        {
        }
        break;
    case QUIT:
        {
            if (vMouse.x >= 0 && vMouse.x <= (8.0 * 8.0 * 3) && vMouse.y >= (8.0 * 8.0) && vMouse.y <= (8.0 * 8.0 * 4) * 2)
            {
                setEstado(INICIAL);
            }
            else if (vMouse.y >= (8.0 * 8.0 * 2) * 2 && vMouse.y <= (8.0 * 8.0) * 3)
            {
                setEstado(PAUSA);
            }
        }
        break;
    case QUITGAME:
        {
            if (vMouse.x >= 0 && vMouse.x <= (8.0 * 8.0 * 3) && vMouse.y >= (8.0 * 8.0) && vMouse.y <= (8.0 * 8.0 * 4) * 2)
            {
                setEstado(INICIAL);
            }
            else if (vMouse.y >= (8.0 * 8.0 * 2) * 2 && vMouse.y <= (8.0 * 8.0) * 3)
            {
                setEstado(EXIT);
            }
        }
        break;
    default:
        break;
    }
}

void Menu::imprimir()
{
    pEstado->imprimir();

    // pEstado->imprimir();
    /*
    float x = getgG()->getWindow()->getPosition().x;
    float y = getgG()->getWindow()->getPosition().y;

    switch (estado)
    {
    case INICIAL:
        {
            escreveTexto("mario++",x,y,8.0);
            escreveTexto("PLAY",x,8.0*8.0+y,8.0);
            escreveTexto("RANK",x,8.0*8.0*2+y,8.0);
        }
        break;
    case PLAY:
        {
            escreveTexto("LEVEL 1",x,y,8.0);
            escreveTexto("LEVEL 2",x,8.0*8.0+y,8.0);
            escreveTexto("LOAD",x,2*8.0*8.0+y,8.0);
        }
        break;
    case PAUSA:
        {

        }
        break;
    case LOAD:
        {

        }

        break;
    case RANK:
        {

        }

    case QUITGAME:
        {
            escreveTexto("SURE?",x,y,8.0);
            escreveTexto("YES",x,y+8.0*8.0,8.0);
            escreveTexto("NO",x,y+2*8.0*8.0,8.0);
        }

        break;
    case QUIT:
        {
            escreveTexto("SURE?",x,y,8.0);
            escreveTexto("YES",x,y+8.0*8.0,8.0);
            escreveTexto("NO",x,y+2*8.0*8.0,8.0);
        }

        break;
    default:
        break;
    }*/
}

void Menu::setPausa(bool p)
{
    pausado = p;
    if (!p)
    {
        setEstado(0);
    }
}

const bool Menu::getPausa() const
{
    return (pausado);
}

void Menu::setEstado(int e)
{
    estado = e;
}
const int Menu::getEstado() const
{
    return (estado);
}
