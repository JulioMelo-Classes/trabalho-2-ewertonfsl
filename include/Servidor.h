#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <vector>

#include "Usuario.h"
#include "CanalTexto.h"

class Servidor {
    private:
        unsigned int id;
        Usuario* dono;
        std::string nome;
        std::string descricao;
        std::string codigoConvite;
        std::vector<CanalTexto> canaisTexto;
        std::vector<Usuario*> participantes;

    public:

        Servidor();

        /**
         * Construtor de novo objeto Servidor.
         * @param id o id de um usuário logado.
         * @param nome o nome do servidor a ser criado.
         */    
        Servidor( int id, std::string nome );
    
        /**
         * Atualiza o id de um servidor.
         * @param id 
         */
        void setId( int id );

        /**
         * Retorna o id de um servidor.
         * @return id de um servidor. 
         */
        int getId();

        /**
         * Atualiza o dono de um servidor.
         * @param dono 
         */
        void setDono( Usuario* dono );

        /**
         * Retorna o dono de um servidor.
         * @return dono de um servidor. 
         */
        int getDono();

        /**
         * Retorna o nome de um servidor.
         * @return nome de um servidor. 
         */
        std::string getNome();
        
        /**
         * Atualiza a descrição de um servidor.
         * @param dono 
         */
        void setDescricao( std::string descricao );
       
        /**
         * Retorna a descrição de um servidor.
         * @return descrição de um servidor. 
         */
        std::string getDescricao();

        /**
         * Atualiza o vetor de participantes do servidor.
         * @param user 
         */
        void addParticipante( Usuario* user );

        /**
         * Atualiza o código de convite de um servidor.
         * @param codigo 
         */
        void setCodigoConvite( std::string codigo );

        /**
         * Retorna o código de convite de um servidor.
         * @return código de convite de um servidor. 
         */
        std::string getCodigoConvite();

        /**
         * Adiciona novo canal ao vetor de canais.
         * @param canal 
         */
        void addCanal( CanalTexto canal );

        /**
         * Percorre vetor de canais e compara nomes para saber se nome fornecido já pertence ao vetor.
         * @return T, caso o nome exista. F, caso contrário.
         */
        bool comparaCanais( std::string nome );

        /**
         * Confere o tamanho do vetor de canais.
         * @return tamanho do vetor de canais.
         */
        int tamanhoCanais();

        /**
         * Atualiza o id de um canal.
         * @param nome 
         */
        void setIdCanal( std::string nome );

        /**
         * Retorna o id de um canal.
         */
        int getIdCanal( std::string nome );

        /**
         * Seta os parâmetros de uma mensagem recebida e insere no vetor de mensagens.
         */
        void recebeMensagem( int idCanal, Usuario* nomeDono, std::string dataHora, std::string mensagem );
        
        /**
         * Lista as mensagens recebidas.
         * @param idCanal 
         */
        void listaMensagens( int idCanal );
};

#endif