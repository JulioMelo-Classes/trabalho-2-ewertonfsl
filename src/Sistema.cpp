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

  Servidor *server = new Servidor( id, nome );

  atribuiIdServidor( *server );

  servidores.push_back( *server );

  server->setDono( usuarios.at(id-1) );
 
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

//   if ( ajeitar condicao )
//   {
//     if ( codigo.length() == 0 )
//     {
//       return "Código de convite do servidor '" + nome + "' removido!";
//     }

//     return "Código de convite do servidor '" + nome + "' modificado!";
//   }
//   else
//     return "Você não pode mudar o código de um servidor que não é seu";
  return "NÃO IMPLEMENTADO"";
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

  // Caso servidor seja aberto (sem código de convite definido).
  if( codigo == "" )
  {
    Servidor server; 
    server.addParticipante( usuarios.at( id-1 ) );

    int idServidor;
    for( auto i = 0; i < servidores.size(); i++ )
    {
      if ( servidores.at(i).getNome() == nome )
        idServidor = i+1;
    }

    usuariosLogados.at( id ).first = idServidor;

    cout << "Visualizando canal: " << usuariosLogados.at( id ).first << endl;
  }
    
  return "Entrou no servidor com sucesso";
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
 * Método responsável por conferir se já existe um email cadastrado durante o cadastro.
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
 * Método responsável por atribuir o id de um usuário.
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

bool Sistema::comparaNomes( string nome )
{
  for( auto i = 0; i < servidores.size(); i++ )
  {
    if( servidores.at(i).getNome() == nome )
      return true;
  }

  return false;
}

void Sistema::atribuiIdServidor( Servidor &server ) 
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