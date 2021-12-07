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
    
        void setId( int id );

        int getId();

        void setDono( Usuario* dono );

        Usuario* getDono();

        std::string getNome();

        void addParticipante( Usuario* userId );
};

#endif