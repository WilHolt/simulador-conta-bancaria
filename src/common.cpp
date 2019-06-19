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
alterarConta(std::string num_, int param){
			std::ifstream conta;
		std::string detalhe_;
		conta.open("data/"+num_+".txt", std::ios::app);
		int cont= 0;
		 std::string _agencia, _numero, _status;
	double _saldo, _limite, _limite_disp;
	std::string _tipo;
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
				_status = std::stoi(detalhe_);

			}						
			if(cont == 4){
				_saldo = std::stoi(detalhe_);

			}						
			if(cont == 5){
				_limite = std::stoi(detalhe_);

			}	
			if(cont == 5){
				_limite_disp = std::stoi(detalhe_);

			}			
		}
		_saldo = param;
		std::string remove_ ="data/"+num_+".txt";
		remove(remove_.c_str());
		std::ofstream conta_;
		conta_.open( "data/"+_numero+".txt", std::ios::app);
		if(conta.is_open()){
			conta_<<_agencia<<'\n';
			conta_<<_numero<<'\n';
			conta_<<_status<<'\n';
			conta_<<_saldo<<'\n';;
			conta_<<_limite<<'\n';
			conta_<<_limite_disp<<'\n';
			conta_<<_tipo<<'\n';
	
	
		}
}
void Excluir(std::string num_){
	std::fstream contas;
	std::string detalhe_;
	contas.open("data/contas.txt", std::ios::app);
	std::vector<std::string> temp;
	while(getline(contas,detalhe_)){
		temp.push_back(detalhe_);
	}
	remove("data/contas.txt");
	for(unsigned int i = 0; i < temp.size() ; i++){
		if(temp[i]!=num_){
			contas<<temp[0]<<'\n';
		}
	}

}

