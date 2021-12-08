#include <iostream>
#include <sstream>
#include <algorithm>

#include "Sistema.h"
#include "Usuario.h"
#include "Servidor.h"

using namespace std;


/* COMANDOS */
string Sistema::quit() {
  return "Finalizando o Concordo";
}

string Sistema::create_user (const string email, const string senha, const string nome) 
{
  if ( validaEmail( email ) ) 
  	return "Este e-mail já está registrado";

  Usuario *user = new Usuario( email, senha, nome );
  
  atribuiIdUsuario( *user );

  usuarios.push_back( user );

  cout << "Criando usuário " + user->getNome() + " (" + user->getEmail() + ")" << endl;
  
  return "Usuário criado";
}

std::string Sistema::delete_user (const std::string email, const std::string senha){
	return "delete_user NÃO IMPLEMENTADO";
}

string Sistema::login(const string email, const string senha) 
{
	Usuario *user = credenciaUser( email, senha );

  if ( user != nullptr )
  {
    pair< int, int > visualizando;
    visualizando.first = 0;
    visualizando.second = 0;

    usuariosLogados.insert( make_pair( user->getId(), visualizando ) );

    return "Logado como " + user->getEmail();
  }
  
  return "Senha ou usuário inválidos";
}

string Sistema::disconnect(int id) {
	return "disconnect NÃO IMPLEMENTADO";
}

string Sistema::create_server(int id, const string nome) 
{
  // Confere se usuário está logado.
	itr = usuariosLogados.find( id );
  if( itr == usuariosLogados.end() )
    return "Necessário fazer login para usar esse comando";

  if( comparaNomes(nome) )
    return "Servidor '" + nome + "' já existe";

  Servidor server = Servidor( id, nome );

  atribuiIdServidor( server );

  server.setDono( usuarios.at(id-1) );

  servidores.push_back( server );

  return "Servidor '" + nome + "' criado";
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) {
	return "set_server_desc NÃO IMPLEMENTADO";
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) 
{
  // Confere se usuário está logado.
	itr = usuariosLogados.find( id );
  if( itr == usuariosLogados.end() )
    return "Necessário fazer login para usar esse comando";

  // Estrutura usada para percorrer vetor de servidores e encontrar seu dono;
  int donoServidor;
  for( auto i = 0; i < servidores.size(); i++ )
  {
    if ( servidores.at(i).getNome() == nome )
      donoServidor = servidores.at(i).getDono();
  }    

  // Caso seja o dono do servidor executando o comando.
  if ( donoServidor == id )
  {
    // Caso o campo codigo não seja fornecido no comando.
    if ( codigo.length() == 0 )
    {
      servidores.at( id-1 ).setCodigoConvite( codigo );
      return "Código de convite do servidor '" + nome + "' removido!";
    }

    servidores.at( id-1 ).setCodigoConvite( codigo );
    return "Código de convite do servidor '" + nome + "' modificado!";
  }

  else
    return "Você não pode mudar o código de um servidor que não é seu";
}

string Sistema::list_servers(int id) {
	return "list_servers NÃO IMPLEMENTADO";
}

string Sistema::remove_server(int id, const string nome) {
	return "remove_server NÃO IMPLEMENTADO";
}

string Sistema::enter_server(int id, const string nome, const string codigo)
{
  // Confere se usuário está logado.
	itr = usuariosLogados.find( id );
  if( itr == usuariosLogados.end() )
    return "Necessário fazer login para usar esse comando";

  // Estrutura usada para percorrer vetor de servidores e encontrar seu dono;
  int donoServidor;
  for( auto i = 0; i < servidores.size(); i++ )
  {
    if ( servidores.at(i).getNome() == nome )
      donoServidor = servidores.at(i).getDono();
  } 

  // Estrutura usada para percorrer vetor de servidores e encontrar seu dono;
  int idServidor;
  for( auto i = 0; i < servidores.size(); i++ )
  {
    if ( servidores.at(i).getNome() == nome )
      idServidor = servidores.at(i).getId();
  }

  // Caso servidor seja aberto (sem código de convite definido).
  if( servidores.at( idServidor-1 ).getCodigoConvite() == "" or donoServidor == id )
  {
    Servidor server;
    server.addParticipante( usuarios.at( id-1 ) );

    usuariosLogados.at( id ).first = idServidor;

    return "Entrou no servidor com sucesso";
  }  

  // Caso seja fornecido o código válido para o servidor.
  if ( codigo == servidores.at( idServidor-1 ).getCodigoConvite() )
  {
    Servidor server;
    server.addParticipante( usuarios.at( id-1 ) );
    
    usuariosLogados.at( id ).first = idServidor;
    
    return "Entrou no servidor com sucesso";
  }

  return "Servidor requer código de convite";
}

string Sistema::leave_server(int id, const string nome) {
	return "leave_server NÃO IMPLEMENTADO";
}

string Sistema::list_participants(int id) {
	return "list_participants NÃO IMPLEMENTADO";
}

string Sistema::list_channels(int id) {
	return "list_channels NÃO IMPLEMENTADO";
}

string Sistema::create_channel(int id, const string nome) {
	return "create_channel NÃO IMPLEMENTADO";
}

string Sistema::remove_channel(int id, const string nome) {
	return "remove_channel NÃO IMPLEMENTADO";
}

string Sistema::enter_channel(int id, const string nome) {
	return "enter_channel NÃO IMPLEMENTADO";
}

string Sistema::leave_channel(int id) {
	return "leave_channel NÃO IMPLEMENTADO";
}

string Sistema::send_message(int id, const string mensagem) {
	return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages(int id) {
	return "list_messages NÃO IMPLEMENTADO";
}


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

/**
 * Atribui um id a um servidor. 
 * @param server um servidor.
 */
void Sistema::atribuiIdServidor( Servidor server ) 
{
  int ultimoServidor = servidores.size();

  if ( ultimoServidor == 0 )
    server.setId( 1 );

  else 
  {
    int novoIdServidor = ultimoServidor + 1;
    server.setId( novoIdServidor );
  }
}
