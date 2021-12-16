#include <algorithm>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "Sistema.h"
#include "Usuario.h"
#include "Servidor.h"

using namespace std;


/* COMANDOS */

string Sistema::quit() 
{
  for( auto i = 0; i < usuarios.size(); i++ )
  {
    delete usuarios.at(i);
  }

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
	itr = usuariosLogados.find( id );
  if( itr == usuariosLogados.end() )
    return "Já está desconectado";

  usuariosLogados.erase( id );

  return "Desconectando usuário " + usuarios.at( id-1 )->getEmail();
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

  int ultimoServidor = servidores.size();

  if ( ultimoServidor == 0 )
    server.setId( 1 );

  else 
  {
    int novoIdServidor = ultimoServidor + 1;
    server.setId( novoIdServidor );
  }

  server.setDono( usuarios.at(id-1) );

  servidores.push_back( server );

  return "Servidor '" + nome + "' criado";
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) 
{
  itr = usuariosLogados.find( id );
  if( itr == usuariosLogados.end() )
    return "Necessário fazer login para usar esse comando";

  // Estrutura usada para percorrer vetor de servidores e encontrar seu id;
  int idServidor;
  for( auto i = 0; i < servidores.size(); i++ )
  {
    if ( servidores.at(i).getNome() == nome )
      idServidor = servidores.at(i).getId();
  }  

  if( !comparaNomes( nome ) )
    return "Servidor '" + nome + "' não existe";

  if( usuarios.at( idServidor-1 )->getId() != id )
    return "Você não pode mudar a descrição de um servidor que não foi criado por você";
  
  servidores.at( idServidor-1 ).setDescricao( descricao );

	return "Descrição do servidor '" + nome + "' modificada";
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) 
{
  // Confere se usuário está logado.
	itr = usuariosLogados.find( id );
  if( itr == usuariosLogados.end() )
    return "Necessário fazer login para usar esse comando";

  // Estrutura usada para percorrer vetor de servidores e encontrar seu id;
  int idServidor;
  for( auto i = 0; i < servidores.size(); i++ )
  {
    if ( servidores.at(i).getNome() == nome )
      idServidor = servidores.at(i).getId();
  }

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
      servidores.at( idServidor-1 ).setCodigoConvite( codigo );
      return "Código de convite do servidor '" + nome + "' removido!";
    }

    servidores.at( idServidor-1 ).setCodigoConvite( codigo );
    return "Código de convite do servidor '" + nome + "' modificado!";
  }

  else
    return "Você não pode mudar o código de um servidor que não foi criado por você";
}

string Sistema::list_servers(int id) 
{
  // Confere se usuário está logado.
	itr = usuariosLogados.find( id );
  if( itr == usuariosLogados.end() )
    return "Necessário fazer login para usar esse comando";
  
  for ( auto i = 0; i < servidores.size(); i++ )
  {
    if ( id == servidores.at(i).getDono() )
      cout << servidores.at(i).getNome() << endl;
  }

  return "";
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

  // Estrutura usada para percorrer vetor de servidores e encontrar seu dono.
  int donoServidor;
  for( auto i = 0; i < servidores.size(); i++ )
  {
    if ( servidores.at(i).getNome() == nome )
      donoServidor = servidores.at(i).getDono();
  } 

  // Estrutura usada para percorrer vetor de servidores e encontrar seu id.
  int idServidor;
  for( auto i = 0; i < servidores.size(); i++ )
  {
    if ( servidores.at(i).getNome() == nome )
    {
      idServidor = servidores.at(i).getId();
    }
  }

  // Validação dos ids
  if ( (idServidor-1) >= 0 and (id-1) >= 0 ) 
  {
    // Caso servidor seja aberto (sem código de convite definido).
    if( servidores.at( idServidor-1 ).getCodigoConvite() == "" or donoServidor == id )
    {
      servidores.at( idServidor-1 ).addParticipante( usuarios.at( id-1 ) );

      usuariosLogados.at( id ).first = idServidor;

      return "Entrou no servidor com sucesso";
    }  

    // Caso seja fornecido o código válido para o servidor.
    if ( codigo == servidores.at( idServidor-1 ).getCodigoConvite() )
    {
      servidores.at( idServidor-1 ).addParticipante( usuarios.at( id-1 ) );
      
      usuariosLogados.at( id ).first = idServidor;
      
      return "Entrou no servidor com sucesso";
    }
  
    return "Servidor requer código de convite";
  }

  return "Servidor '" + nome + "' não encontrado";
}

// CONFERIR REMOÇAO
string Sistema::leave_server(int id, const string nome) 
{
  // Confere se usuário está logado.
	itr = usuariosLogados.find( id );
  if( itr == usuariosLogados.end() )
    return "Necessário fazer login para usar esse comando";

  // Estrutura usada para percorrer vetor de servidores e encontrar seu id.
  int idServidor = 0;
  for( auto i = 0; i < servidores.size(); i++ )
  {
    if ( servidores.at(i).getNome() == nome )
    {
      idServidor = servidores.at(i).getId();
    }
  }

  // Validação dos ids
  if ( (idServidor-1) >= 0 and (id-1) >= 0 ) 
  {
    if( comparaNomes( nome ) )
    {
      if( usuariosLogados.at(id).first == idServidor )
      {
        usuariosLogados.at( id ).first = 0;
        usuariosLogados.at( id ).second = 0;
        return "Saindo do servidor '" + nome + "'";
      }
    
      bool estaEmServidor;
      for( auto i = 0; i < servidores.size(); i++ )
      {
        if( itr == usuariosLogados.end() )
          estaEmServidor = false;
      }

      if( estaEmServidor )
        return "Você não está nesse servidor";
    }
  }
  
  return "Servidor '" + nome + "' não encontrado";
}

string Sistema::list_participants(int id) 
{
  // Confere se usuário está logado.
	itr = usuariosLogados.find( id );
  if( itr == usuariosLogados.end() )
    return "Necessário fazer login para usar esse comando";

  //tentar usar os que estão sendo visualizados em usuarioLogado iterator

  if( usuariosLogados.at(id).first == 0)
    return "Você não está em qualquer servidor";

  for ( auto i = 1; i <= usuariosLogados.size(); i++ )
  {
    if( usuariosLogados.at(i).first == usuariosLogados.at(id).first )
    {
      cout << usuarios.at(i-1)->getNome() << endl;
    }
  }
  
  return "";
}

string Sistema::list_channels(int id) {
	return "list_channels NÃO IMPLEMENTADO";
}

string Sistema::create_channel(int id, const string nome) 
{
  // Confere se usuário está logado.
	itr = usuariosLogados.find( id );
  if( itr == usuariosLogados.end() )
    return "Necessário fazer login para usar esse comando";

  CanalTexto channel = CanalTexto( id, nome );

  // Confere se o usuário do id fornecido está visualizando um servidor.
  if( usuariosLogados.at(id).first > 0 )
  {
    for( auto i = 0; i < servidores.size(); i++ )
    {
      if( servidores.at(i).comparaCanais( nome ) )
        return "Canal '" + nome + "' já existe";
      else
      {
        servidores.at(i).addCanal( channel );

        servidores.at(i).setIdCanal( nome );

        return "Canal '" + nome + "' criado";
      }
    }
  }

  return "Você não está em um servidor";
}

string Sistema::remove_channel(int id, const string nome) {
	return "remove_channel NÃO IMPLEMENTADO";
}


//checkin 4.1 e 4.2 ok
string Sistema::enter_channel(int id, const string nome)
{
	itr = usuariosLogados.find( id );
  if( itr == usuariosLogados.end() )
    return "Necessário fazer login para usar esse comando";

  // Confere se o usuário do id fornecido está visualizando um servidor.
  if( usuariosLogados.at(id).first > 0 )
  {
    for( auto i = 0; i < servidores.size(); i++ )
    {
      if( servidores.at(i).comparaCanais( nome ) )
      {
        usuariosLogados.at(id).second = servidores.at(i).getIdCanal( nome );

        return "Entrou no canal '" + nome + "'";
      }
    }
    
    return "Canal '" + nome + "' não existe";
  }

  return "Você não está em um servidor";
}

string Sistema::leave_channel(int id) {
	return "leave_channel NÃO IMPLEMENTADO";
}

//checkin 4.3 e 4.4 ok
string Sistema::send_message(int id, const string mensagem)
{
	itr = usuariosLogados.find( id ); //esse iterator não precisa ser membro da classe, vc poderia declarar ele localmente neste método
  if( itr == usuariosLogados.end() )
    return "Necessário fazer login para usar esse comando";

  if( usuariosLogados.at(id).second > 0 )
  {
    auto tempo = time( nullptr );
    auto dataHoraAtual = *localtime( &tempo );

    stringstream ss;
    ss << put_time( &dataHoraAtual, "<%d/%m/%Y - %H:%M>: " );
    string dataHora = ss.str();

    for( auto i = 0; i < servidores.size(); i++ )
    {
      if( servidores.at(i).getId() == usuariosLogados.at(id).first )
      {
        //A data/hora poderia ser criada dentro do construtor de mensagem
        servidores.at(i).recebeMensagem( usuariosLogados.at(id).second, usuarios.at(id-1), dataHora, mensagem  );
        return "Mensagem enviada";
      }
    }
  }  

  return "Você não está em um canal";
}

string Sistema::list_messages(int id) 
{
	itr = usuariosLogados.find( id );
  if( itr == usuariosLogados.end() )
    return "Necessário fazer login para usar esse comando";

  if( usuariosLogados.at(id).second > 0 )
  {
    for( auto i = 0; i < servidores.size(); i++ )
    {
      if( servidores.at(i).getId() == usuariosLogados.at(id).first )
      {
        servidores.at(i).listaMensagens( usuariosLogados.at(id).second );
      }
    }

    return "";
  }  

  return "Você não está em um canal";
}
