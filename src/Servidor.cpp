#include <iostream>

#include "Servidor.h"

using namespace std;

Servidor::Servidor(){};

/**
 * Construtor de novo objeto Servidor.
 * @param id o id de um usuário logado.
 * @param nome o nome do servidor a ser criado.
 */
Servidor::Servidor( int id, const string nome )
{
    this-> id = id;
    this->nome = nome;
}

void Servidor::setId( int id )
{
    this->id = id;
}

int Servidor::getId()
{
    return id;
}

void Servidor::setDono( Usuario* dono )
{
    this->dono = dono;
}

Usuario* Servidor::getDono()
{
    return dono;
}

string Servidor::getNome()
{
    return nome;
}

void Servidor::addParticipante( Usuario* userId )
{
    participantes.push_back( userId );
}