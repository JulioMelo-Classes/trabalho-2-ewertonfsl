#include <iostream>
#include <algorithm>

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
    this->id = id;
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
 * Atualiza a descrição de um servidor.
 * @param dono 
 */
void Servidor::setDescricao( string descricao )
{
    this->descricao = descricao;
}

/**
 * Retorna a descrição de um servidor.
 * @return descrição de um servidor. 
 */
string Servidor::getDescricao()
{
    return descricao;
}

/**
 * Atualiza o vetor de participantes do servidor.
 * @param user 
 */
void Servidor::addParticipante( Usuario* user )
{
    participantes.push_back( user );
}

/**
 * Atualiza o código de convite de um servidor.
 * @param codigo 
 */
void Servidor::setCodigoConvite( string codigo )
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

/**
 * Adiciona novo canal ao vetor de canais.
 * @param canal 
 */
void Servidor::addCanal( CanalTexto canal )
{
    canaisTexto.push_back( canal );
}

/**
 * Percorre vetor de canais e compara nomes para saber se nome fornecido já pertence ao vetor.
 * @return T, caso o nome exista. F, caso contrário.
 */
bool Servidor::comparaCanais( string nome )
{
    for( auto i = 0; i < canaisTexto.size(); i++ )
    {
        if( canaisTexto.at(i).getNome() == nome )
            return true;
    }
    return false;
}

/**
 * Confere o tamanho do vetor de canais.
 * @return tamanho do vetor de canais.
 */
int Servidor::tamanhoCanais()
{
    return canaisTexto.size();
}

/**
 * Atualiza o id de um canal.
 * @param nome 
 */
void Servidor::setIdCanal( string nome )
{
    for( auto i = 0; i < canaisTexto.size(); i++ )
    {
        if( canaisTexto.at(i).getNome() == nome )
            canaisTexto.at(i).setId( i+1 );
    }
}

/**
 * Retorna o id de um canal.
 */
int Servidor::getIdCanal( string nome )
{
    for( auto i = 0; i < canaisTexto.size(); i++ )
    {
        if( canaisTexto.at(i).getNome() == nome )
            return canaisTexto.at(i).getId();
    }
    return 0;
}

/**
 * Seta os parâmetros de uma mensagem recebida e insere no vetor de mensagens.
 */
void Servidor::recebeMensagem( int idCanal, Usuario* nomeDono, string dataHora, string mensagem )
{
    Mensagem setaMensagem;  
    setaMensagem.setUsuarioNome( nomeDono );
    setaMensagem.setDataHora( dataHora );
    setaMensagem.setConteudo( mensagem );
    
    canaisTexto.at(idCanal-1).addMensagem( setaMensagem );
}

/**
 * Lista as mensagens recebidas.
 * @param idCanal 
 */
void Servidor::listaMensagens( int idCanal )
{
    canaisTexto.at(idCanal-1).listaMensagens();
}