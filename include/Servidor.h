#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <vector>

#include "Usuario.h"

class Servidor {
    private:
        int id;
        Usuario* dono;
        std::string nome;
        std::string descricao;
        std::string codigoConvite;
        // vector<CanalTexto> canaisTexto;
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
         * Atualiza o vetor de participantes do servidor.
         * @param userId 
         */
        void addParticipante( Usuario* userId );

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
};

#endif