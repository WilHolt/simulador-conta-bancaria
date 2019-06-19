#include "common.h"
#include <cstdio>
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
void
listarContas(){
	std::ifstream contas;
	contas.open("data/contas.txt", std::ios::app);
	std::string conta_;
	while(getline(contas,conta_)){
		std::cout<<conta_<<'\n';
	}

}
void 
detalhesConta(std::string num_){
		std::ifstream conta;
		std::string detalhe_;
		conta.open("data/"+num_+".txt", std::ios::app);

		while(getline(conta,detalhe_)){
		std::cout<<detalhe_<<'\n';
	}

}
void
alterarConta(std::string num_){
			std::ifstream conta;
		std::string detalhe_;
		conta.open("data/"+num_+".txt", std::ios::app);
		int cont= 0;
		std::string filename, std::string _agencia, std::string _numero, std::string _status,
	double _saldo,
	double _limite,
	double _limite_disp,
	std::string _tipo
		while(getline(conta,detalhe_)){
			if(cont == 0){
				//agencia
				_agencia = detalhe_;
			}
			if(cont == 2){
				//numero
				_numero = detalhe_;

			}
			if(cont == 3){
				status_ = detalhe_;

			}						
			if(cont == 4){
				saldo = detalhe_;

			}						
			if(cont == 5){
				_limite = detalhe_;

			}	
			if(cont == 5){
				_limite_disp = detalhe_;

			}			
		}
		std::string remove_ ="data/"+num_+".txt";
		remove(remove_);
}
void Excluir()

