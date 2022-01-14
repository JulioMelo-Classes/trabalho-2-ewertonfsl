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

# Avaliação
## Funcionalidades
- A1.2 ok
- A1.3 nok
- A1.4 ok
- A2.1 ok
- A2.2 ok
- A2.3 ok
- A2.4 ok
- A2.5 ok
- A2.6 nok
- A2.7 ok
- A2.8 40%
Você faz boa parte da checagem mas não remove o usuario efetivamente da lista de participantes do servidor
- A2.9 20%
Aqui você deveria ter listado os participantes do servidor em que o usuário está. Um participante pode não estar logado e pode não estar visualizando o servidor,
na prática você precisava iterar na lista de usuários que foram adicionados no servidor e imprimir os nomes.
- B1.1 nok
- B1.2 ok
- B1.3 ok
- B1.4 nok
- B1.5 nok
- B2.1 ok
- B2.2 ok

## Classes
- Servidor ok
- Canal ok
- Mensagem ok

## Boas Práticas
- Documentação 80%
Faltou documentar os atributos
- Testes ok
- Organização ok

## Observações
Como conversamos acho que voce poderia tercerizar mais as atividades para as classes que são inclusas em sistema, fora isso acho que ficou ok.