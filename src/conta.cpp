 #include <iostream>
 #include "conta.h"
 #include "mbasic.h"
#include "execoes.h"
#include <iomanip>
 
 using namespace mbasic;
//OPERACOES
	/**
       * O Construtor.
       * Um Construtor default;
    */
Operacao::Operacao(){}
	/**
       * O Construtor.
       * Um Construtor com parametros de descrição, valor e flag;
       * @param _descricao_op
       * @param _valor_op
       * @param _flag
    */
Operacao::Operacao(std::string _descricao_op, double _valor_op, std::string _flag):
 descricao_op(_descricao_op), valor_op(_valor_op), flag(_flag){}
	/**
       * O Destrutor.
       * Um Destrutor default;
    */
Operacao::~Operacao(){}



//CONTA
	/**
       * O Construtor.
       * Um Construtor default;
    */
 Conta::Conta() {}
	/**
       * O Destrutor.
       * Um Destrutor default;
    */
 Conta::~Conta(){}
	/**
       * O Construtor.
       * Um Construtor com parametros;
       * @param _nome
       * @param _numero
       * @param _saldo
    */
 Conta::Conta(std::string _nome, std::string _numero, double _saldo):
 	nome(_nome), numero(_numero), saldo(_saldo) {}



	/**
       * Getter Nome.
       * Utilizado para pegar somente o nome do proprietario da conta
    */
std::string
Conta::getNome() {
	return nome;
 }
	/**
       * Getter Numero.
       * Utilizado para pegar somente o numero da Conta
    */
std::string
Conta::getNumero() {
	return numero;
}


double
Conta::getSaldo() {
	return saldo;
}

	/**
       * Sobrecarga de operador extração.
       * Sobrecarga de operador extração de conta unica;
    */
std::ostream& operator<< (std::ostream &o, Conta  &t) {
	o << std::setfill (' ') << std::setw (10) <<"Nome:"<<t.getNome() << " | " 
		<< std::setfill ('.') << std::setw (20) <<"Conta:"<< t.getNumero() << " | " 
		<< std::setfill (' ') << std::setw (10) <<"Saldo:" << t.getSaldo() << " | " ;
		return o;
}
	/**
       * Realizar Saque.
       * Função de saque para retirar dinheiro de uma conta unica.
    */
void
Conta::saque(int retirada){
	if (retirada > (this->saldo) ) throw saldoInvalido();
 	this->saldo= MathBasic::dif<double>(saldo,retirada);
	std::string _descricao_op = "Saque";
	double _valor_op= retirada;
	std::string _flag = "s";
  Operacao op(_descricao_op, _valor_op,_flag);
 historico.push_back(op);
}
	/**
       * Realizar Deposito.
       * Função de deposito para adicionar dinheiro de uma conta unica.
    */
void
Conta::deposito(int valor){
	if (valor == 0  ) throw valorZero();
 	this->saldo= MathBasic::add<double>(saldo,valor);
	std::string _descricao_op = "Deposito";
	double _valor_op= valor;
	std::string _flag = "s";
Operacao op(_descricao_op, _valor_op,_flag);
 historico.push_back(op);
}
	/**
       * Realizar Transferencia.
       * Função para realizar a transferencia de dinheiro de uma conta para outra.
	   * @see saque()
	   * @see deposito()
    */
void Conta::transferencia(std::shared_ptr<Conta> t1, std::shared_ptr<Conta> t2, double valor){
	try{
		t2->deposito(valor);
	}catch(saldoInvalido& e){
		std::cerr<<e.what()<<std::endl;
	}
	t1->saque(valor);
	std::string _descricao_op = "Transferencia";
	double _valor_op= valor;
	std::string _flag = "s";
	Operacao op(_descricao_op, _valor_op,_flag);
 	historico.push_back(op);
}
	/**
       * Mostrar Saldo.
       * Função de mostrar apenas saldo.
    */
void Conta::printSaldo(){
	std::cout<<"Conta:"<<this->numero;
	std::cout<<"   Saldo:"<<this->saldo<<std::endl;
}
	/**
       * Mostrar Extrato.
       * Função para mostrar extrato de todas as operações realizadas.
    */
void Conta::printExtrato(){
  std::cout << *this << '\n';
	for (auto it = this->historico.begin(); it != this->historico.end(); it++) {
    std::cout << *it << '\n';
  }
	//std::cout<<this->(**historico);
}
