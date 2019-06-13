#include "common.h"

void
criarConta(std::string filename, std::string _numero){
	std::ofstream contas;
	contas.open(filename, std::ios::app);
	std::ofstream conta;
	if(contas.is_open()){
		std::cout<<_numero<<'\n';
	}

}