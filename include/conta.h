#ifndef _CONTA_H_
#define _CONTA_H_

#include <iostream>
#include <vector>
#include <fstream>

class Operacao{
private:
	std::string descricao_op;
	double valor_op;
	std::string flag;
public:
Operacao();
Operacao(std::string _descricao_op, double _valor_op, std::string _flag);
~Operacao();
void Print();
friend std::ostream& operator<< (std::ostream &o, Operacao const &t){
	o<<t.descricao_op << "\n" << "valor:" << t.valor_op <<"   "<<"Flag:"<< t.flag;
	return o;
}
};


class Conta{
public:
	Conta();
	Conta(	std::string _agencia, std::string _numero, std::string _status,
	double _saldo,
	double _limite,
	double _limite_disp);
	virtual ~Conta();
protected:
	std::string agencia;
	std::string numero;
	std::string status;
	double saldo;
	double limite;
	double limite_disp;
	std::vector<Operacao> historico;
protected:
	//friend double operator+ (Conta  &t1, Conta  &t2);
	//friend double operator- (Conta  &t1, Conta  &t2);
public:
	// getters
	std::string getAgencia();
	std::string getNumero();
	std::string getStatus();
	double getSaldo();
	double getLimite();
	double getLimite_disp();
	// setters
	int setSaldo();
	int setLimite();
	double setLimite_disp();
	std::vector<Operacao> fatura;
	//metodos menu
	void saque(int retirada);
	void deposito(int valor);
	void transferencia(Conta &t1,Conta &t2,double valor);
	void printSaldo();
	void printExtrato();
	friend std::ostream& operator<< (std::ostream &o, Conta const &t);
public:
	virtual std::ostream& print(std::ostream&) const = 0;
};

#endif
