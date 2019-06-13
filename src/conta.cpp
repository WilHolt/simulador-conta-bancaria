 #include <iostream>
 #include "conta.h"
 #include "mbasic.h"
#include "execoes.h"

 
 using namespace mbasic;
//OPERACOES
Operacao::Operacao(){}

Operacao::Operacao(std::string _descricao_op, double _valor_op, std::string _flag):
 descricao_op(_descricao_op), valor_op(_valor_op), flag(_flag){}

Operacao::~Operacao(){}



//CONTA
 Conta::Conta() {}

 Conta::~Conta(){}

 Conta::Conta(std::string _agencia, std::string _numero, std::string _status,
	double _saldo,
	double _limite,
	double _limite_disp):
 	numero(_numero), status(_status), saldo(_saldo), limite(_limite), limite_disp(_limite_disp) {}




std::string
Conta::getAgencia() {
	return agencia;
 }

std::string
Conta::getNumero() {
	return numero;
}

std::string
Conta::getStatus() {
	return status;
}
double
Conta::getSaldo() {
	return saldo;
}
double
Conta::getLimite() {
	return limite;
}
double
Conta::getLimite_disp() {
	return limite_disp;
}

std::ostream& operator<< (std::ostream &o, Conta const &t) {
	return t.print(o);
}

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

void Conta::transferencia(Conta &t1, Conta &t2, double valor){
	try{
		t2.deposito(valor);
	}catch(saldoInvalido& e){
		std::cerr<<e.what()<<std::endl;
	}
	t1.saque(valor);
		std::string _descricao_op = "Transferencia";
	double _valor_op= valor;
	std::string _flag = "s";
	Operacao op(_descricao_op, _valor_op,_flag);
 historico.push_back(op);
}
void Conta::printSaldo(){
	std::cout<<"Conta:"<<this->numero;
	std::cout<<"   Saldo:"<<this->saldo<<std::endl;
}
void Conta::printExtrato(){
  std::cout << *this << '\n';
	for (auto it = this->historico.begin(); it != this->historico.end(); it++) {
    std::cout << *it << '\n';
  }
	//std::cout<<this->(**historico);
}
