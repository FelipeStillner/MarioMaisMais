#pragma once
#include"../Afix.h"
#include"../Ente.h"
using std::vector;
using std::string;
using namespace Gerenciadores;
class Botao : public Ente 
{   
    private:
    static vector<sf::IntRect*>* letras;
    string texto;
    sf::Keyboard::Key opt;
    sf::Vector2f pos;


    public:
    Botao(sf::Keyboard::Key  o = sf::Keyboard::Comma, sf::Vector2f p = sf::Vector2f(), string t = NULL);
    ~Botao();
    void escreveTexto();
    static void inicializaLetras();
    static void destroiLetras();
    void executar(float dt = 0);
    void imprimir();
    const sf::Keyboard::Key getOpt() const ;
    
};