#include <iostream>
#include <sstream>
#include <algorithm>

#include "Sistema.h"
#include "Usuario.h"

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
  
  atribuiId( *user );

  usuarios.push_back( *user );

  cout << "Criando usuário " + user->getNome() + " (" + user->getEmail() + ")" << endl;
  
  return "Usuário criado";
}

std::string Sistema::delete_user (const std::string email, const std::string senha){
	return "delete_user NÃO IMPLEMENTADO";
}

string Sistema::login(const string email, const string senha) {
	return "login NÃO IMPLEMENTADO";
}

string Sistema::disconnect(int id) {
	return "disconnect NÃO IMPLEMENTADO";
}

string Sistema::create_server(int id, const string nome) {
	return "create_server NÃO IMPLEMENTADO";
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) {
	return "set_server_desc NÃO IMPLEMENTADO";
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {
	return "set_server_invite_code NÃO IMPLEMENTADO";
}

string Sistema::list_servers(int id) {
	return "list_servers NÃO IMPLEMENTADO";
}

string Sistema::remove_server(int id, const string nome) {
	return "remove_server NÃO IMPLEMENTADO";
}

string Sistema::enter_server(int id, const string nome, const string codigo) {
	return "enter_server NÃO IMPLEMENTADO";
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
    if ( usuarios[i].getEmail() == email)
	  return true;
  }

  return false;
}

/**
 * Método responsável por medir o tamanho do vetor usuários.
 * @return a quantidade de usuários ou o valor nulo, caso ainda não hajam usuários criados. 
 */
Usuario* Sistema::buscaUltimo() 
{
  int tamanho = usuarios.size();

  if (tamanho == 0)
	  return nullptr;

  return &usuarios[ tamanho-1 ];
}

/**
 * Método responsável por atribuir o id de um usuário.
 * @param user um usuário cadastrado no sistema.
 */
void Sistema::atribuiId( Usuario &user ) 
{
  Usuario *ultimoUsuario = buscaUltimo();

  if ( ultimoUsuario == nullptr )
    user.setId( 1 );

  else 
  {
    int novoId = ultimoUsuario->getId() + 1;
    user.setId( novoId );
  }
}