#include "Mensagem.h"
#include "Usuario.h"


using namespace std;

Mensagem::Mensagem(){}

/**
 * Construtor de um novo objeto Mensagem.
 * @param enviadaPor usuário que enviou a mensagem.
 * @param conteudo conteúdo da mensagem.
 */
Mensagem::Mensagem( Usuario* enviadaPor, string conteudo )
{
    this->enviadaPor = enviadaPor;
    this->conteudo = conteudo;
}

/**
 * Atualiza o id de uma mensagem.
 * @param id 
 */
void Mensagem::setId( int id )
{
    this->id = id;
}

/**
 * Retorna o id de uma mensagem.
 * @return id de uma mensagem. 
 */   
int Mensagem::getId()
{
    return id;
}

/**
 * Atualiza a data e a hora que uma mensagem foi enviada.
 * @param dataHora 
 */
void Mensagem::setDataHora( string dataHora )
{
    this->dataHora = dataHora;
}

/**
 * Retorna a data e a hora que uma mensagem foi enviada.
 * @return data e hora de envio de mensagem. 
 */
string Mensagem::getDataHora()
{
    return dataHora;
}

/**
 * Atualiuza o nome do usuário que enviou uma mensagem.
 * @param enviadaPor 
 */
void Mensagem::setUsuarioNome( Usuario* enviadaPor )
{
    this->enviadaPor = enviadaPor;
}

/**
 * Retorna o nome do usuário que enviou uma mensagem.
 * @return nome do usuário que enviou uma mensagem. 
 */
string Mensagem::getUsuarioNome()
{
    return enviadaPor->getNome();
}

/**
 * Atualiza o conteúdo de uma mensagem.
 * @param conteudo 
 */
void Mensagem::setConteudo( string conteudo )
{
    this->conteudo = conteudo;
}

/**
 * Retorna o conteúdo de uma mensagem.
 * @return conteúdo de uma mensagem.
 */
string Mensagem::getConteudo()
{
    return conteudo;
}