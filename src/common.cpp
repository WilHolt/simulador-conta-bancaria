#include "common.h"
#include "conta.h"
#include <cstdio>
#include <memory>
	/**
       * Criar Conta.
       * Função do menu que cria uma conta, adiciona a conta ao banco de dados data/contas.txt
       * e cria um arquivo unico para cada conta, além de mostrar o menu de criar conta.
       * @param filename
    */
void
criarConta(std::string filename){
					std::string _nome, _numero, _tipo;
					double _saldo;
	std::cout<<" -------------  Criar Conta ----------------";
	std::cout<<" Digite o nome do proprietario da conta";
	std::cin>>_nome;
	std::cout<<" Digite o numero da conta";
	std::cin>>_numero;
	std::cout<<" Digite o saldo";
	std::cin>>_saldo;
	std::ofstream contas;
	contas.open("data/contas.txt", std::ios::app);
	std::ofstream conta;
	conta.open( "data/"+_numero+".txt", std::ios::app);

	if(contas.is_open()){
		std::cout<<"ENTREI NO LEITOR DE ARQUIVO"<<'\n';
		contas<<_numero<<'\n';
	}
	if(conta.is_open()){
		conta<<_nome<<'\n';
		conta<<_numero<<'\n';
		conta<<_saldo<<'\n';



	}
	}
	/**
       * Listar Contas.
       * Lista todas as contas buscando do banco de daos data/contas.txt
    */
void
listarContas(){
	std::ifstream contas;
	contas.open("data/contas.txt", std::ios::app);
	std::string conta_;
	while(getline(contas,conta_)){
		std::cout<<conta_<<'\n';
	}

}
/**
       * Detalhes de Contas.
       * Busca a conta pelo arquivo que corresponde ao seu numero;
       * @param num_
    */
void 
detalhesConta(std::string num_){
		std::ifstream conta;
		std::string detalhe_;
		conta.open("data/"+num_+".txt", std::ios::app);

		while(getline(conta,detalhe_)){
		std::cout<<detalhe_<<'\n';
	}

}
	/**
       * Alterar Conta.
       * alterar dados de uma conta única.
       * @param num_
       * @param param
    */
void
alterarConta(std::string num_, double param){
			std::ifstream conta;
		std::string detalhe_;
		conta.open("data/"+num_+".txt", std::ios::app);
		int cont= 0;
		 std::string _nome, _numero;
	double _saldo;
	std::string _tipo;
		while(getline(conta,detalhe_)){
			if(cont == 0){
				//agencia
				_nome = detalhe_;
			}
			if(cont == 2){
				//numero
				_numero = detalhe_;

			}
			if(cont == 4){
				_saldo = std::stoi(detalhe_);

			}						

			cont++;		
		}
		_saldo = param;
		std::string remove_ ="data/"+num_+".txt";
		remove(remove_.c_str());
		std::ofstream conta_;
		conta_.open( "data/"+_numero+".txt", std::ios::app);
		if(conta.is_open()){
			conta_<<_nome<<'\n';
			conta_<<_numero<<'\n';
			conta_<<_saldo<<'\n';;

		}
}
	/**
       * Excluir Conta.
       * Exclui a conta e o seu arquivo unico.
       * @param num_
    */
void excluirConta(std::string num_){
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
	/**
       * Retornar Conta.
       * Função para retornar as contas que a pessoa quer para instanciar o objeto
       * e poder fazer as operações.
       * @param num_
       * @return shared_ptr<Conta>
    */
std::shared_ptr<Conta>  
retornarConta(std::string num_){
			std::ifstream conta;
		std::string detalhe_;
		conta.open("data/"+num_+".txt", std::ios::app);
		int cont =0;
		std::string _nome, _numero, _tipo;
		double _saldo;
		while(getline(conta,detalhe_)){
			if(cont == 0){
				//agencia
				_nome = detalhe_;
			}
			if(cont == 2){
				//numero
				_numero = detalhe_;

			}
						
			if(cont == 4){
				_saldo = std::stoi(detalhe_);

			}						
	
			cont++;		
		}
		auto temp = std::make_shared<Conta>(_nome, _numero, _saldo);
		return temp ;
}
/**
       * Sair.
       * Sair do loop de menu.
       * @param num_
    */
bool sair(){
return false;
}
