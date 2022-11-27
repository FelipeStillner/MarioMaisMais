#include "Save.h"
Save::Save() : nome1(""), nome2("")
{
    entrou = false;
}
Save::~Save()
{
}
void Save::imprimir()
{
    if (!entrou || !(pFase->getMltplyr()))
    {
        Botao bot(sf::Vector2f(0, 0), nome1);
        bot.imprimir();
    }
    else
    {
        Botao bot(sf::Vector2f(0, 0), nome2);
        bot.imprimir();
    }
}
Estado *Save::eExecutar()
{
    executar();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        if (entrou || !(pFase->getMltplyr()))
        {
            salvarPontuacao();
            return (ePausa);
        }
        else
        {
            entrou = true;
        }
    }

    return (this);
}
Fase *Save::getFase() const
{
    return pFase;
}
void Save::setFase(int i)
{
}
void Save::executar(const float dt)
{

    sf::Event evento;
    if (gG->getWindow()->waitEvent(evento))
    {
        if (evento.type == sf::Event::KeyPressed)
        {
            string *nome = NULL;

            if (pFase->getMltplyr() && entrou)
            {
                nome = &nome2;
            }
            else
            {
                nome = &nome1;
            }

            if (evento.key.code == sf::Keyboard::Backspace && nome->size())
            {
                nome->pop_back();
            }
            else if ((evento.key.code != sf::Keyboard::Enter))
            {
                if (nome->size() <= 10)
                {
                    char ch = static_cast<char>(evento.text.unicode + 'A');
                    nome->push_back(ch);
                }
            }
        }
    }
}
void Save::salvarPontuacao()
{
    int p1 = pFase->getJogador(1)->getPont();
    std::ofstream arquivo;
    arquivo.open("ClassesAuxiliares/Estados/Rank.dat", std::ios::app);
    arquivo << std::endl;
    arquivo << nome1 << ' ' << p1;
    if (pFase->getMltplyr())
    {
        int p2 = pFase->getJogador(2)->getPont();
        arquivo << std::endl;
        arquivo << nome2 << ' ' << p2;
    }
    arquivo.close();
}
void Save::limpaSave()
{
    nome1.erase();
    nome2.erase();
    entrou = false;
}
