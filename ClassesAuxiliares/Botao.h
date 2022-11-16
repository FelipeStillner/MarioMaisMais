#pragma once

#include"../Afix.h"
#include"../Ente.h"

using std::vector;
using std::string;
using namespace Gerenciadores;

namespace ClassesAuxiliares
{

class Botao : public Ente 
{   
private:
    static vector<sf::IntRect*>* letras;
    string texto;
    sf::Vector2f pos;
public:
    Botao(sf::Vector2f p = sf::Vector2f(), string t = NULL);
    ~Botao();
    void executar(float dt = 0);
    void imprimir();
    void escreveTexto();
    static void inicializaLetras();
    static void destroiLetras();
};

}

using namespace ClassesAuxiliares;