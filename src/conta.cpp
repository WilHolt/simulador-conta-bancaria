 #include <iostream>
 #include "conta.h"

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

std::ostream& operator<< (std::ostream &o, Conta const &p) {
	return p.print(o);
}

