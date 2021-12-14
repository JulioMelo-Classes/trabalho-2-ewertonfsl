#include <iostream>

#include "CanalTexto.h"

using namespace std;

CanalTexto::CanalTexto(){}

/**
 * Construtor de um novo objeto CanalTexto.
 * @param id o id de um usuário logado.
 * @param nome o nome do canal a ser criado.
 */
CanalTexto::CanalTexto( int id, string nome  )
{
    this->id = id;
    this->nome = nome;
}

/**
 * Atualiza o id de um canal.
 * @param id 
 */
void CanalTexto::setId( int id )
{
    this->id = id;
}

/**
 * Retorna o id de um canal.
 * @return o id de um canal.
 */
int CanalTexto::getId()
{
    return id;
}

/**
 * Atualiza o nome de um canal.
 * @param nome 
 */
void CanalTexto::setNome( std::string nome )
{
    this->nome = nome;
}

/**
 * Retorna o nome de um canal.
 * @return o nome de um canal.
 */
string CanalTexto::getNome()
{
    return nome;
}

/**
 * Atualiza o dono de um canal.
 * @param dono 
 */
void CanalTexto::setDono( Usuario* dono )
{
    this->dono = dono;
}

/**
 * Retorna o id do dono de um canal.
 * @return id do dono de um canal. 
 */
int CanalTexto::getDonoId()
{
    return dono->getId();
}

/**
 * Atualiza o vetor de mensagens.
 * @param mensagem 
 */
void CanalTexto::addMensagem(  Mensagem mensagem )
{   
    mensagens.push_back( mensagem );
}

/**
 * Confere o tamanho do vetor de mensagens.
 * @return tamanho do vetor de mensagens.
 */
int CanalTexto::tamanhoMensagens()
{
    return mensagens.size();
}

/**
 * Imprime as mensagens enviadas em um canal com informações de data e hora.
 */
void CanalTexto::listaMensagens()
{
    for( auto i = 0; i < mensagens.size(); i++ )
    {
        if( mensagens.size() > 0 )
            cout << mensagens.at(i).getUsuarioNome() << " " << mensagens.at(i).getDataHora() << mensagens.at(i).getConteudo() << endl;
        else
            cout << "Sem mensagens para exibir" << endl;
    }
}