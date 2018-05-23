 #include <iostream>
 #include "conta.h"
Operacao::Operacao(){}

Operacao::Operacao(std::string _descricao_op, double _valor_op, std::string _flag):
 descricao_op(_descricao_op), valor_op(_valor_op), flag(_flag){}

Operacao::~Operacao(){}

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
 this->saldo= saldo-retirada;
	std::string _descricao_op = "Saque";
	double _valor_op= retirada;
	std::string _flag = "s";
Operacao op(_descricao_op, _valor_op,_flag);
 historico.push_back(op);
}
void
Conta::deposito(int valor){
 this->saldo= saldo+valor;
	std::string _descricao_op = "Deposito";
	double _valor_op= valor;
	std::string _flag = "s";
Operacao op(_descricao_op, _valor_op,_flag);
 historico.push_back(op);
}

