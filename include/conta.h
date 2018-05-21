#ifndef _CONTA_H_
#define _CONTA_H_

#include <iostream>
#include <vector>
class Operacao{
	private:
	std::string descricao_op;
	int valor_op;
	std::string flag;
}
class Produto
{
public:
	Conta();
	Conta(std::string _codigo, std::string _descricao, short _preco);
	virtual ~Conta();
protected:
	std::string agencia;
	std::string numero;
	std::string status;
	double saldo;
	double limite;
	double limite_disp;
	friend double operator+ (Produto  &t1, Produto  &t2);
	friend double operator- (Produto  &t1, Produto  &t2);
public:
	// getters
	int getSaldo();
	int getLimite();
	double getLimite_disp();
	// setters
	void setCodBarras(std::string _codigo);
	void setDescricao(std::string _descricao);
	void setPreco(double _preco);
	std::vector<Operacao> fatura;
	//

	friend std::ostream& operator<< (std::ostream &o, Produto const &t);
private:
	virtual std::ostream& print(std::ostream&) const = 0;
};

#endif
