#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <fstream>
#include <string>
#include "conta.h"
#include "corrente.h"
#include "poupanca.h"
using namespace std;

int main(int argc, char const *argv[])
{
	std::vector<shared_ptr<Conta>> Itau;
	Itau.push_back(make_shared<Corrente>("A32","3173","Especial",333.1, 1000, 677.9,"Corrente"));
	Itau.push_back(make_shared<Poupanca>("A32","3333","Especial",333.1, 1000, 677.9,"Poupanca"));

	for(auto i= Itau.begin(); i != Itau.end(); i++){
	std::cout<<(**i)<<"\n"<<std::endl;
	}
	std::cout<<"antes do saque"<<std::endl;
	Itau[0]->saque(10);
	std::cout<<"depois do saque"<<std::endl;
	cout<<*Itau[0]<<std::endl;
	std::cout<<"depois do deposito"<<std::endl;
	Itau[0]->deposito(10);
	cout<<*Itau[0]<<std::endl;
	std::cout<<"depois da transferencia"<<std::endl;
	Itau[0]->transferencia(*Itau[0],*Itau[1], 100);
	cout<<*Itau[0]<<std::endl;
	cout<<*Itau[1]<<std::endl;
	std::cout<<"print saldo:";
	Itau[1]->printSaldo();


	// std::vector<shared_ptr<Produto>> lista;
	// std::fstream file_stream;
	// file_stream.open("data/data.dat", std::fstream::in);
	// if (!file_stream) {
	// 	std::cout << "pifou" << '\n';
	// }
	// std::string buffer;
	// while(std::getline(file_stream, buffer)){
	// 	std::vector<std::string> aux;
	// 	std::string token;
	// 	std::istringstream iss(buffer);
	// 	std::string labels;
	// 	while(std::getline(iss, token, ',')){
	// 		labels = token;
	// 		aux.push_back(token);
	// 	}
	// 	std::string tipo(aux[0]);
	// 	std::string codigo(aux[1]);
	// 	std::string descricao(aux[2]);
	// 	if (tipo=="Fruta") {
	// 		std::string _preco=aux[3];
	// 		double preco =std::stod( _preco);
	// 		lista.push_back(make_shared<Fruta>(codigo,descricao,preco,"01/10/2017",18));
	// 	}
	// 	if (tipo=="Bebida") {
	// 		std::string _preco=aux[3];
	// 		double preco =std::stod( _preco);
	// 		std::string _teor=aux[4];
	// 		short teor =std::stoi( _teor);
	// 		lista.push_back(make_shared<Bebida>(codigo,descricao,preco, teor));
	// 	}
	// 	if (tipo=="Roupa") {
	// 		std::string _preco=aux[3];
	// 		std::string marca=aux[4];
	// 		std::string sexo=aux[5];
	// 		std::string tamanho=aux[6];
	// 		double preco =std::stod( _preco);
	// 		lista.push_back(make_shared<Roupa>(codigo,descricao,preco,marca,sexo,tamanho));
	// 	}

	// 	//lista.push_back(make_shared<>(codigo,descricao,8.70,"01/10/2017",18));

	// }
	// // //lista.push_back(make_shared<Fruta>("001002003-45","Maca verde",8.70,"01/10/2017",18));
	// // lista.push_back(make_shared<Fruta>("001002004-44","Laranja",4.75,"23/09/2017",15));
	// // lista.push_back(make_shared<Fruta>("001002005-11","Limao verde",2.30,"01/10/2017",25));
	// // lista.push_back(make_shared<Roupa>("001002005-11","Camisa Azul",2.30,"Lacoste",'M',"gg"));
	// // lista.push_back(make_shared<Bebida>("001002005-11","Whisky Vermelho",2.30,12));
	// for (auto i = lista.begin(); i != lista.end(); ++i)
	// {
	// 	std::cout << (**i) << std::endl;

	// }

	// // double resultado = *lista[1]+*lista[2];
	// // std::cout<<"\n"<<"resultado:"<<resultado<<std::endl;
	// // return 0;
}
