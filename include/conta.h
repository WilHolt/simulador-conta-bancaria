#ifndef _CONTA_H_
#define _CONTA_H_

#include <iostream>
#include <vector>
class Operacao{
private:
	std::string descricao_op;
	double valor_op;
	std::string flag;
public:
Operacao();
Operacao(std::string _descricao_op, double _valor_op, std::string _flag);
~Operacao();
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
	void transferencia(Conta &t1,Conta &t2 );
	void printSaldo();
	void printExtrato();
	friend std::ostream& operator<< (std::ostream &o, Conta const &t);
public:
	virtual std::ostream& print(std::ostream&) const = 0;
};

#endif
