#ifndef _FRUTA_H_
#define _FRUTA_H_

#include "produto.h"

class Fruta : public Produto
{
public:
	Fruta();
	Fruta(std::string _codigo, std::string _descricao, short _preco,
			std::string _data, short _validade);
	~Fruta();
private:
	std::string m_data_lote;
	short m_validade;
public:
	// getters
	std::string getDataLote();
	short getValidade();
	// setters
	void setDataLote(std::string _data);
	void setValidade(short _validade);
	//sobrecarga
		friend double operator+ (Produto const &t1, Produto const &t2);
private:
	std::ostream& print(std::ostream &o) const;
};

#endif
