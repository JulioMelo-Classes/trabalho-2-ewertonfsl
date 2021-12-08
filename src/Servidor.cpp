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

/**
 * Atualiza o id de um servidor.
 * @param id 
 */
void Servidor::setId( int id )
{
    this->id = id;
}

/**
 * Retorna o id de um servidor.
 * @return id de um servidor. 
 */
int Servidor::getId()
{
    return id;
}

/**
 * Atualiza o dono de um servidor.
 * @param dono 
 */
void Servidor::setDono( Usuario* dono )
{
    this->dono = dono;
}

/**
 * Retorna o dono de um servidor.
 * @return dono de um servidor. 
 */
int Servidor::getDono()
{
    return dono->getId();
}

/**
 * Retorna o nome de um servidor.
 * @return nome de um servidor. 
 */
string Servidor::getNome()
{
    return nome;
}

/**
 * Atualiza o vetor de participantes do servidor.
 * @param userId 
 */
void Servidor::addParticipante( Usuario* userId )
{
    participantes.push_back( userId );
}

/**
 * Atualiza o código de convite de um servidor.
 * @param codigo 
 */
void Servidor::setCodigoConvite( std::string codigo )
{
    this->codigoConvite = codigo;
}

/**
 * Retorna o código de convite de um servidor.
 * @return código de convite de um servidor. 
 */
string Servidor::getCodigoConvite()
{
    return codigoConvite;
}