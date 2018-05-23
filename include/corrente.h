#ifndef CORRENTE_H
#define CORRENTE_H
#include "conta.h"


class Corrente : public Conta{
private:
	std::string tipo;

public:
	Corrente(std::string _agencia, std::string _numero, std::string _status,
	double _saldo,
	double _limite,
	double _limite_disp,
	std::string _tipo);
	~Corrente();

private:
	std::ostream& print(std::ostream &o) const;
};

#endif
