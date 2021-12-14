## Como compilar o projeto (em ambiente Linux)
1. Pelo terminal, vá até a pasta do projeto, por exemplo:
```
cd Downloads/trabalho-2-ewerton-lima
```
2. Crie e entre na pasta build:
```
mkdir build
cd build
```
3. Execute os comandos do `cmake`

```
cmake ..
cmake --build .
```

## Para executar
Você pode rodar o sistema: 
```
./concordo
```
E em seguida digitar os comandos manualmente.

Ou pode criar um arquivo de texto com uma lista de comandos (um por linha), inserir na pasta data e executar o sistema redirecionando esse arquivo como entrada padrão:
```console
./concordo < ../data/meus_proprios_testes.txt
```

## Para executar o conjunto de testes
Ainda na pasta build, você pode executar o conjunto de testes pré-definido por mim, separados de acordo com os tópicos da especificação, com todos os casos de uso:
```console
./concordo < ../data/A1_nao_logado.txt
./concordo < ../data/A2_interacoes_basicas_logado.txt
./concordo < ../data/B1_gestao_canais.txt
./concordo < ../data/B2_gestao_mensagens.txt
```

## Funcionalidades não implementadas
```console
A1.3 - Deletar um usuário.

A2.6 - Remover servidor.

B1.1 - Listar canais do servidor
B1.4 - Sair do canal
B1.5 - Remover um canal no servidor

```

## Limitações
Não poder usar atributos públicos nas classes, principalmente ao manipular vetores.
Também me enrolei um pouco para modularizar trechos de código então houve certa repetição.