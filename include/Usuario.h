#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario
{
    private:
        int id;
        std::string nome;
        std::string email;
        std::string senha;

    public:

        /**
         * Construtor de novo objeto Usuario.
         * @param email o email de um usuário.
         * @param senha a senha de um usuário.
         * @param nome o nome de um usuário.
         */
        Usuario( std::string email, std::string senha, std::string nome);
        
        /**
         * Atualiza o id de um usuário.
         * @param id
         */
        void setId( int id );
        
        /**
         * Retorna o id de um usuário.
         * @return id de um usuário. 
         */
        int getId();

        /**
         * Retorna o nome de um usuário.
         * @return nome de um usuário. 
         */
        std::string getNome();

        /**
         * Retorna o email de um usuário.
         * @return email de um usuário. 
         */
        std::string getEmail();

        /**
         * Retorna a senha de um usuário.
         * @return senha de um usuário. 
         */
        std::string getSenha();
};

#endif
