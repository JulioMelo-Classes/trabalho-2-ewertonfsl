#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <vector>

#include "Usuario.h"

class Mensagem {
    private:
        unsigned int id;
        std::string dataHora;
        Usuario* enviadaPor;
        std::string conteudo;

    public:

    Mensagem();

    /**
     * Construtor de um novo objeto Mensagem.
     * @param enviadaPor usuário que enviou a mensagem.
     * @param conteudo conteúdo da mensagem.
     */
    Mensagem( Usuario* enviadaPor, std::string conteudo );

    /**
     * Atualiza o id de uma mensagem.
     * @param id 
     */
    void setId( int id );

    /**
     * Retorna o id de uma mensagem.
     * @return id de uma mensagem. 
     */
    int getId();

    /**
     * Atualiza a data e a hora que uma mensagem foi enviada.
     * @param dataHora 
     */
    void setDataHora( std::string dataHora );

    /**
     * Retorna a data e a hora que uma mensagem foi enviada.
     * @return data e hora de envio de mensagem. 
     */
    std::string getDataHora();

    /**
     * Atualiuza o nome do usuário que enviou uma mensagem.
     * @param enviadaPor 
     */
    void setUsuarioNome( Usuario* enviadaPor );

    /**
     * Retorna o nome do usuário que enviou uma mensagem.
     * @return nome do usuário que enviou uma mensagem. 
     */
    std::string getUsuarioNome();

    /**
     * Atualiza o conteúdo de uma mensagem.
     * @param conteudo 
     */
    void setConteudo( std::string conteudo );
    
    /**
     * Retorna o conteúdo de uma mensagem.
     * @return conteúdo de uma mensagem.
     */
    std::string getConteudo();
};

#endif