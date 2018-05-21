#ifndef _CONTA_H_
#define _CONTA_H_

#include <iostream>

class Produto
{
public:
	Produto();
	Produto(std::string _codigo, std::string _descricao, short _preco);
	virtual ~Produto();
protected:
	std::string agencia;
	std::string numero;
	std::string status;
	double saldo;
	double limite;
	double limite_d;
	friend double operator+ (Produto  &t1, Produto  &t2);
	friend double operator- (Produto  &t1, Produto  &t2);
public:
	// getters
	std::string getCodBarras();
	std::string getDescricao();
	double getPreco();
	// setters
	void setCodBarras(std::string _codigo);
	void setDescricao(std::string _descricao);
	void setPreco(double _preco);
	//

	friend std::ostream& operator<< (std::ostream &o, Produto const &t);
private:
	virtual std::ostream& print(std::ostream&) const = 0;
};

#endif
