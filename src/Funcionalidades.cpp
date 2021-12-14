#include "Sistema.h"

using namespace std;


/**
 * Percorre vetor de usuários e compara emails para saber se um usuário já foi cadastrado com o email fornecido.
 * @param email o email do usuário informado no comando create-user.
 * @return T caso email já esteja cadastrado. F caso contrário. 
 */
bool Sistema::validaEmail( string email ) 
{
  for (int i = 0; i < usuarios.size(); i++) 
  {
    if ( usuarios.at(i)->getEmail() == email)
	  return true;
  }

  return false;
}

/**
 * Atribui o id de um usuário.
 * @param user um usuário cadastrado no sistema.
 */
void Sistema::atribuiIdUsuario( Usuario &user ) 
{
  int ultimoUsuario = usuarios.size();

  if ( ultimoUsuario == 0 )
    user.setId( 1 );

  else 
  {
    int novoIdUsuario = ultimoUsuario + 1;
    user.setId( novoIdUsuario );
  }
}

/**
 * Confere se email e senha fornecidos pertencem a um usuário cadastrado.
 * @param email o email do usuário.
 * @param senha a senha de um usuário.
 * @return Caso T, retorna o usuário na posição em que foi encontrado. Caso F, retorna nulo.
 */
Usuario* Sistema::credenciaUser( string email, string senha )
{
  for ( auto i = 0; i < usuarios.size(); i++ )
  {
    bool validaUser = usuarios.at(i)->getEmail() == email and usuarios.at(i)->getSenha() == senha;

    if( validaUser )
      return usuarios.at(i);
  }

  return nullptr;
}

/**
 * Percorre vetor de servidores e compara nomes para saber se nome fornecido já pertence ao vetor.
 * @param nome o nome de um servidor.
 */
bool Sistema::comparaNomes( string nome )
{
  for( auto i = 0; i < servidores.size(); i++ )
  {
    if( servidores.at(i).getNome() == nome )
      return true;
  }

  return false;
}
