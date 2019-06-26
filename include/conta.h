#ifndef _CONTA_H_
#define _CONTA_H_

#include <memory>
#include <iostream>
#include <vector>
#include <fstream>
/**
  @param int o primeiro número(in)
  @param int o segundo número(in)
  @brief a descrição da fun~ção
  @author José Wilder de Morais Venancio
*/

/**
 * @brief Operação
 * 
 * Classe de operação, que representa as operações que podem ser divididas
 */

/*! CLASSE QUE REPRESENTA AS OPERAÇÕES REALIZADAS */
class Operacao{
private:
	std::string descricao_op;
	double valor_op;
	std::string flag;
public:
	/**
       * O Construtor.
       * Um Construtor default;
    */
Operacao();
	/**
       * O Construtor.
       * Um Construtor com parametros de descrição, valor e flag;
       * @param _descricao_op
       * @param _valor_op
       * @param _flag
    */
Operacao(std::string _descricao_op, double _valor_op, std::string _flag);
	/**
       * O Destrutor.
       * Um Destrutor default;
    */
~Operacao();

void Print();
	/**
       * Sobrecarga de opreador de extraão.
       * sobrecarga feita para mostrar a operação usando apenas o cout;
    */
friend std::ostream& operator<< (std::ostream &o, Operacao const &t){
	o<<t.descricao_op << "\n" << "valor:" << t.valor_op <<"   "<<"Flag:"<< t.flag;
	return o;
}
};

/**
 * @brief Classe Conta.
 * 
 * Classe que representa as contas de um banco, com suas operações e atributos.
 */
class Conta{
public:
	/**
       * O Construtor.
       * Um Construtor default;
    */
	Conta();
	/**
       * O Construtor.
       * Um Construtor com parametros;
       * @param _nome
       * @param _numero
       * @param _saldo
    */
	Conta(	std::string _nome, std::string _numero, double _saldo);
		/**
       * O  Destrutor.
       * Um Destrutor default;
    */
	virtual ~Conta();
protected:
	std::string nome;
	// std::string agencia;
	std::string numero;
	// std::string status;
	double saldo;
	// double limite;
	// double limite_disp;
	std::vector<Operacao> historico;
protected:
	//friend double operator+ (Conta  &t1, Conta  &t2);
	//friend double operator- (Conta  &t1, Conta  &t2);
public:
	// getters
	/**
       * Getter Nome.
       * Utilizado para pegar somente o nome do proprietario da conta
    */
	std::string getNome();
	/**
       * Getter Numero.
       * Utilizado para pegar somente o numero da Conta
    */
	std::string getNumero();

	/**
       * Getter Saldo.
       * Utilizado para pegar o Saldo da Conta
    */
	double getSaldo();

	// setters
	/**
       * Setter Saldo.
       * Usado para colocar um valor de saldo para conta
    */
	int setSaldo();

	
	std::vector<Operacao> fatura;
	//metodos menu

	/**
       * Realizar Saque.
       * Função de saque para retirar dinheiro de uma conta unica.
    */
	void saque(int retirada);
	/**
       * Realizar Deposito.
       * Função de deposito para adicionar dinheiro de uma conta unica.
    */
	void deposito(int valor);
	/**
       * Realizar Transferencia.
       * Função para realizar a transferencia de dinheiro de uma conta para outra.
	   * @see saque()
	   * @see deposito()
    */
	void transferencia(std::shared_ptr<Conta> t1,std::shared_ptr<Conta> t2,double valor);
	/**
       * Mostrar Saldo.
       * Função de mostrar apenas saldo.
    */
	void printSaldo();
	/**
       * Mostrar Extrato.
       * Função para mostrar extrato de todas as operações realizadas.
    */
	void printExtrato();
	/**
       * Sobrecarga de operador extração.
       * Sobrecarga de operador extração de conta unica;
    */
	friend std::ostream& operator<< (std::ostream &o, Conta  &t);
public:
	/**
       * Metodo virtual de print
       * 
    */
	// virtual std::ostream& print(std::ostream&) const = 0;
};

#endif
