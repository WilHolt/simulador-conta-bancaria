#ifndef _COMMOM_H_
#define _COMMOM_H_
#include "conta.h"
#include <memory>
	/**
       * Criar Conta.
       * Função do menu que cria uma conta, adiciona a conta ao banco de dados data/contas.txt
       * e cria um arquivo unico para cada conta, além de mostrar o menu de criar conta.
       * @param filename
    */
void
criarConta(std::string filename);
	/**
       * Listar Contas.
       * Lista todas as contas buscando do banco de daos data/contas.txt
    */
void 
listarContas();
	/**
       * Detalhes de Contas.
       * Busca a conta pelo arquivo que corresponde ao seu numero;
       * @param num_
    */
void 
detalhesConta(std::string num_);
	/**
       * Alterar Conta.
       * alterar dados de uma conta única.
       * @param num_
       * @param param
    */
void
alterarConta(std::string num_, double param);
	/**
       * Excluir Conta.
       * Exclui a conta e o seu arquivo unico.
       * @param num_
    */
void 
excluirConta(std::string num_);
	/**
       * Sair.
       * Sair do loop de menu.
       * @param num_
    */
bool sair();
	/**
       * Retornar Conta.
       * Função para retornar as contas que a pessoa quer para instanciar o objeto
       * e poder fazer as operações.
       * @param num_
       * @return shared_ptr<Conta>
    */
std::shared_ptr<Conta>  retornarConta(std::string num_);

#endif
