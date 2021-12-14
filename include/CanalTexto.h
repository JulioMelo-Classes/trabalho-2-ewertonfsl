#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include <vector>

#include "Usuario.h"
#include "Mensagem.h"

class CanalTexto {
    private:
        unsigned int id;
        std::string nome;
        Usuario* dono;
        std::vector<Mensagem> mensagens;

    public:

        CanalTexto();

        /**
         * Construtor de um novo objeto CanalTexto.
         * @param id o id de um usuário logado.
         * @param nome o nome do canal a ser criado.
         */
        CanalTexto( int id, std::string nome );

        /**
         * Atualiza o id de um canal.
         * @param id 
         */
        void setId( int id );

        /**
         * Retorna o id de um canal.
         * @return o id de um canal.
         */
        int getId();

        /**
         * Atualiza o nome de um canal.
         * @param nome 
         */
        void setNome( std::string nome );

        /**
         * Retorna o nome de um canal.
         * @return o nome de um canal.
         */
        std::string getNome();

        /**
         * Atualiza o dono de um canal.
         * @param dono 
         */
        void setDono( Usuario* dono );

        /**
         * Retorna o dono de um canal.
         * @return o dono de um canal.
         */
        int getDonoId();

        /**
         * Atualiza o vetor de mensagens.
         * @param mensagem 
         */
        void addMensagem( Mensagem mensagem );

        /**
         * Confere o tamanho do vetor de mensagens.
         * @return tamanho do vetor de mensagens.
         */
        int tamanhoMensagens();

        /**
         * Imprime as mensagens enviadas em um canal com informações de data e hora.
         */
        void listaMensagens();
};

#endif