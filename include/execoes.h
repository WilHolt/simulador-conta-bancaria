#ifndef _EXCECOES_H
#define _EXCECOES_H

#include <stdexcept>
using std::invalid_argument;
using std::out_of_range;
	/**
       * !Saldo Inválido.
       * exceção para detectar que saldo é inválido.
   */
class saldoInvalido : public invalid_argument {
public:
    saldoInvalido() : invalid_argument("Operacao invalida: Você não possui Saldo suficiente") {}
};
	/**
       * !Valor Zero.
       * exceção para detectar que o valor digitado foi Zero.
   */
class valorZero : public invalid_argument {
public:
    valorZero() : invalid_argument("Operacao invalida: Adicione algum valor!") {}
};
	/**
       * !Conta Inexistente.
       * execão para detectar que a conta não existe para realizar operações;
   */
class contaInexistente : public invalid_argument {
public:
    contaInexistente() : invalid_argument("Operacao invalida: Conta Inválida") {}
};





#endif