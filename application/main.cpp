#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <fstream>
#include <string>
#include "conta.h"
#include "corrente.h"
#include "poupanca.h"
#include <stdexcept>  
#include "execoes.h"
#include "common.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int option;
	while(true){
		std::cout<<"Selecione uma operação"<<std::endl
		<<"1. Criar Conta"<<std::endl
		<<"2. Listar Contas"<<std::endl		
		<<"3. Alterar Conta"<<std::endl		
		<<"4. Detalhe de uma Conta"<<std::endl		
		<<"5. Excluir Conta"<<std::endl		
		<<"6. Realizar Transferencia"<<std::endl		
		<<"7. Realizar Depósito"<<std::endl		
		<<"8. Realizar Saque"<<std::endl		
		<<"9. Sair"<<std::endl;	
		cin>>option;
		
		switch(option){
			case 1:
			std::cout<<" Criar Conta";
			break;
			case 2:
			break;
			case 3:
			break;
			case 4:
			break;
			case 5:
			break;
			case 6:
			break;
			case 7:
			break;
			case 8:
			break;
		};

	};
	criarConta(argv[1],"a32","32211","Especial",313.2,1000,6555.4,"Corrente");
	std::vector<shared_ptr<Conta>> Itau;

	listarContas();
	std::cout <<'\n';
	detalhesConta("32211");
	Itau.push_back(make_shared<Corrente>("A32","3173","Especial",333.1, 1000, 677.9,"Corrente"));
	Itau.push_back(make_shared<Poupanca>("A32","3333","Especial",333.1, 1000, 677.9,"Poupanca"));

	for(auto i= Itau.begin(); i != Itau.end(); i++){
	std::cout<<(**i)<<"\n"<<std::endl;
	}
	std::cout<<"\n"<<"antes do catch"<<std::endl;
	try{
	cout<<"SAQUE ACIMA DO SALDO"<<endl;
	Itau[0]->saque(10000);
	}catch(saldoInvalido& e){
		cerr<< e.what()<<endl;
	}

	try{
		cout<<"FORA DO RANGE"<<endl;
		Itau.at(3)=Itau[0];
	}catch(const out_of_range& e){
		cerr<<e.what()<<endl;
	}	


	try{
		cout<<"PASSANDO CONTAS INEXISTENTES"<<endl;
		if(Itau[0]){ throw contaInexistente();
		}else if(Itau[1]){
			throw contaInexistente();
		}
	Itau[0]->transferencia(*Itau[0],*Itau[1], 100);
	}catch(contaInexistente& e){
		cerr<<e.what()<<endl;
	}	

	cout<<"MOSTRANDO CONTAS:"<<endl;
	cout<<*Itau[0]<<std::endl;

	cout<<*Itau[1]<<std::endl;

	std::cout<<"\n"<<"print saldo:"<<"\n";

	Itau[1]->printSaldo();

	std::cout<<"\n"<<"print extrato 1:"<<"\n";

	Itau[0]->printExtrato();

	std::cout<<"\n"<<"print extrato 2:"<<"\n";

	Itau[1]->printExtrato();

}
