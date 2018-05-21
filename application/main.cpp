#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <fstream>
#include <string>
#include "conta.h"

using namespace std;

int main(int argc, char const *argv[])
{

	std::vector<shared_ptr<Produto>> lista;
	std::fstream file_stream;
	file_stream.open("data/data.dat", std::fstream::in);
	if (!file_stream) {
		std::cout << "pifou" << '\n';
	}
	std::string buffer;
	while(std::getline(file_stream, buffer)){
		std::vector<std::string> aux;
		std::string token;
		std::istringstream iss(buffer);
		std::string labels;
		while(std::getline(iss, token, ',')){
			labels = token;
			aux.push_back(token);
		}
		std::string tipo(aux[0]);
		std::string codigo(aux[1]);
		std::string descricao(aux[2]);
		if (tipo=="Fruta") {
			std::string _preco=aux[3];
			double preco =std::stod( _preco);
			lista.push_back(make_shared<Fruta>(codigo,descricao,preco,"01/10/2017",18));
		}
		if (tipo=="Bebida") {
			std::string _preco=aux[3];
			double preco =std::stod( _preco);
			std::string _teor=aux[4];
			short teor =std::stoi( _teor);
			lista.push_back(make_shared<Bebida>(codigo,descricao,preco, teor));
		}
		if (tipo=="Roupa") {
			std::string _preco=aux[3];
			std::string marca=aux[4];
			std::string sexo=aux[5];
			std::string tamanho=aux[6];
			double preco =std::stod( _preco);
			lista.push_back(make_shared<Roupa>(codigo,descricao,preco,marca,sexo,tamanho));
		}

		//lista.push_back(make_shared<>(codigo,descricao,8.70,"01/10/2017",18));

	}
	// //lista.push_back(make_shared<Fruta>("001002003-45","Maca verde",8.70,"01/10/2017",18));
	// lista.push_back(make_shared<Fruta>("001002004-44","Laranja",4.75,"23/09/2017",15));
	// lista.push_back(make_shared<Fruta>("001002005-11","Limao verde",2.30,"01/10/2017",25));
	// lista.push_back(make_shared<Roupa>("001002005-11","Camisa Azul",2.30,"Lacoste",'M',"gg"));
	// lista.push_back(make_shared<Bebida>("001002005-11","Whisky Vermelho",2.30,12));
	for (auto i = lista.begin(); i != lista.end(); ++i)
	{
		std::cout << (**i) << std::endl;

	}

	// double resultado = *lista[1]+*lista[2];
	// std::cout<<"\n"<<"resultado:"<<resultado<<std::endl;
	// return 0;
}
