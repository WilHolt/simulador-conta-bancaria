#ifndef POUPANCA_H
#define POUPANCA_H
#include "conta.h"


class Poupanca: public Conta{
private:
	std::string tipo;

public:
	Poupanca(std::string _agencia, std::string _numero, std::string _status,
	double _saldo,
	double _limite,
	double _limite_disp,
	std::string _tipo);
	~Poupanca();

private:
	std::ostream& print(std::ostream &o) const;
};

#endif