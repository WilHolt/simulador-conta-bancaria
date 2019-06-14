#include "common.h"

void
criarConta(std::string filename, std::string _agencia, std::string _numero, std::string _status,
	double _saldo,
	double _limite,
	double _limite_disp,
	std::string _tipo){
	std::ofstream contas;
	contas.open("data/contas.txt", std::ios::app);
	std::ofstream conta;
	conta.open( "data/"+_numero+".txt", std::ios::app);

	if(contas.is_open()){
		std::cout<<"ENTREI NO LEITOR DE ARQUIVO"<<'\n';
		contas<<_numero<<'\n';
	}
	if(conta.is_open()){
		conta<<_agencia<<'\n';
		conta<<_numero<<'\n';
		conta<<_status<<'\n';
		conta<<_saldo<<'\n';;
		conta<<_limite<<'\n';
		conta<<_limite_disp<<'\n';
		conta<<_tipo<<'\n';


	}

}