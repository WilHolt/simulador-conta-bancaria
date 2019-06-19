#ifndef _COMMOM_H_
#define _COMMOM_H_
#include "conta.h"
void
criarConta(std::string filename, std::string _agencia, std::string _numero, std::string _status,
	double _saldo,
	double _limite,
	double _limite_disp,
	std::string _tipo);

void 
listarContas();
void 
detalhesConta(std::string num_);
void
AlterarConta();
void 
excluirConta(std::string num_);

#endif
