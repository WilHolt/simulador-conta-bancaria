#ifndef _EXCECOES_H
#define _EXCECOES_H

#include <stdexcept>
using std::invalid_argument;
using std::out_of_range;
class saldoInvalido : public invalid_argument {
public:
saldoInvalido() : invalid_argument("Operacao invalida: Você não possui Saldo suficiente") {}
};

class valorZero : public invalid_argument {
public:
valorZero() : invalid_argument("Operacao invalida: Adicione algum valor!") {}
};
class contaInexistente : public invalid_argument {
public:
contaInexistente() : invalid_argument("Operacao invalida: Conta Inválida") {}
};





#endif