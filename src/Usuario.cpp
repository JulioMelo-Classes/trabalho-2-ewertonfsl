#include <sstream>

#include "Usuario.h"

using namespace std;

/**
 * Construtor de novo objeto Usuario.
 * @param email o email de um usuário.
 * @param senha a senha de um usuário.
 * @param nome o nome de um usuário.
 */
Usuario::Usuario( const string email, const string senha, const string nome ) 
{
    this->email = email;
    this->senha = senha;
    this->nome = nome;
}

/**
 * Atualiza o id de um usuário.
 * @param id
 */
void Usuario::setId( int id ) 
{
    this->id = id;
}

/**
 * Retorna o id de um usuário.
 * @return id de um usuário. 
 */
int Usuario::getId()
{
    return id;
}

/**
 * Retorna o nome de um usuário.
 * @return nome de um usuário. 
 */
string Usuario::getNome()
{
    return nome;
}

/**
 * Retorna o email de um usuário.
 * @return email de um usuário. 
 */
string Usuario::getEmail()
{
    return email;
}

/**
 * Retorna a senha de um usuário.
 * @return senha de um usuário. 
 */
string Usuario::getSenha() 
{
    return senha;
}
