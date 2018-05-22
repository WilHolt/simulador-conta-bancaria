#include <iomanip>
 #include "corrente.h"


 Corrente::Corrente(std::string _agencia, std::string _numero, std::string _status,
	double _saldo,
	double _limite,
	double _limite_disp,
	std::string _tipo):
 	Conta(_agencia, _numero, _status, _saldo, _limite, _limite_disp), tipo(_tipo) {}
 Corrente::~Corrente(){}
 std::ostream& 

Corrente::print(std::ostream &o) const {
	o << std::setfill (' ') << std::setw (10) <<"Agencia:"<<agencia << " | " 
		<< std::setfill ('.') << std::setw (20) <<"Numero:"<< numero << " | " 
		<< std::setfill (' ') << std::setw (5) <<"Status:"<<status << " | "
		<< std::setfill (' ') << std::setw (3) <<"Tipo" << tipo << " | " 
		<< std::setfill (' ') << std::setw (10) <<"Saldo:" <<saldo << " | " 
		<< std::setfill (' ') << std::setw (3) <<"Limite Total:" << limite << " | " 
		<< std::setfill (' ') << std::setw (3) <<"Limite Disponivel" << limite_disp << " | " ;

	return o;
}