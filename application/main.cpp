#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <fstream>
#include <string>
#include "conta.h"
#include <stdexcept>  
#include "execoes.h"
#include "common.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int option;
	bool instance = true;
	while(instance){
		system("clear");
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
			{
				criarConta("contasmak"); 
				break;
			}
			case 2:
			{
				listarContas();
				break;
			}
			case 3:
			{
				std::string num_;
				double valor;
				std::cout<<"Digite o Numero da Conta: "<<std::endl;
				std::cin>>num_;
				std::cout<<"Digite o valor para alterar: "<<std::endl;
				std::cin>>valor;
				alterarConta(num_, valor);
				break;
			}
			case 4:
			{
				std::string num_;
				std::cout<<"Digite o Numero da Conta para ser Mostrada: "<<std::endl;
				std::cin >> num_;
				detalhesConta(num_);
				break;
			}
			case 5:
			{
				std::string num_;
				std::cout<<"Digite o Numero da Conta para ser excluida: "<<std::endl;
				std::cin >> num_;
				excluirConta(num_);
				break;
			}
			case 6:
			{
				std::string num1;
				std::string num2;
				std::cout<<"Digite o Numero da Conta 1: "<<std::endl;
				std::cin >> num1;
				std::cout<<"Digite o Numero da Conta 2: "<<std::endl;
				std::cin >> num2;

				auto conta1 = retornarConta(num1);
				auto conta2 = retornarConta(num2);
				cout<<*conta1;
				std::cout<<std::endl;
				cout<<*conta2;
				conta1->transferencia(conta1,conta2,100);
				std::cout<<endl;
				std::cout<<endl;
				std::cout<<endl;
				conta2->printSaldo();
				system("PAUSE");
				break;
			}
			case 7:
			{	
				std::string num_;
				double valor;
				std::cout<<"Digite o Numero da Conta: "<<std::endl;
				std::cin>>num_;
				std::cout<<"Digite o valor de depósito: "<<std::endl;
				std::cin>>valor;
				auto conta = retornarConta(num_);
				conta->deposito(valor);
				break;
			}
			case 8:
			{
				std::string num_;
				double valor;
				std::cout<<"Digite o Numero da Conta: "<<std::endl;
				std::cin>>num_;
				std::cout<<"Digite o valor de saque: "<<std::endl;
				std::cin>>valor;
				auto conta = retornarConta(num_);
				conta->saque(valor);
				break;
			}
			case 9:
			{
				 instance = sair();
				break; 
			}
		};

	};
	// criarConta(argv[1],"a32","32211","Especial",313.2,1000,6555.4,"Corrente");
	// std::vector<shared_ptr<Conta>> Itau;

	// std::cout <<'\n';
	// Itau.push_back(make_shared<Corrente>("A32","3173","Especial",333.1, 1000, 677.9,"Corrente"));
	// Itau.push_back(make_shared<Poupanca>("A32","3333","Especial",333.1, 1000, 677.9,"Poupanca"));

	// for(auto i= Itau.begin(); i != Itau.end(); i++){
	// std::cout<<(**i)<<"\n"<<std::endl;
	// }
	// std::cout<<"\n"<<"antes do catch"<<std::endl;
	// try{
	// cout<<"SAQUE ACIMA DO SALDO"<<endl;
	// Itau[0]->saque(10000);
	// }catch(saldoInvalido& e){
	// 	cerr<< e.what()<<endl;
	// }

	// try{
	// 	cout<<"FORA DO RANGE"<<endl;
	// 	Itau.at(3)=Itau[0];
	// }catch(const out_of_range& e){
	// 	cerr<<e.what()<<endl;
	// }	


	// try{
	// 	cout<<"PASSANDO CONTAS INEXISTENTES"<<endl;
	// 	if(Itau[0]){ throw contaInexistente();
	// 	}else if(Itau[1]){
	// 		throw contaInexistente();
	// 	}
	// Itau[0]->transferencia(*Itau[0],*Itau[1], 100);
	// }catch(contaInexistente& e){
	// 	cerr<<e.what()<<endl;
	// }	

	// cout<<"MOSTRANDO CONTAS:"<<endl;
	// cout<<*Itau[0]<<std::endl;

	// cout<<*Itau[1]<<std::endl;

	// std::cout<<"\n"<<"print saldo:"<<"\n";

	// Itau[1]->printSaldo();

	// std::cout<<"\n"<<"print extrato 1:"<<"\n";

	// Itau[0]->printExtrato();

	// std::cout<<"\n"<<"print extrato 2:"<<"\n";

	// Itau[1]->printExtrato();

}
