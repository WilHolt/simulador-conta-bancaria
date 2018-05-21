#ifndef _ROUPA_H_
#define _ROUPA_H_

#include "produto.h"

class Roupa : public Produto
{
public:
	Roupa();
	Roupa(std::string _codigo, std::string _descricao, short _preco,
		std::string marca, std::string sexo, std::string tamanho);
		~Roupa();
	private:
		std::string marca;
		std::string sexo;
		std::string tamanho;
	public:
		// getters
		std::string getDataLote();
		short getValidade();
		// setters
		void setDataLote(std::string _data);
		void setValidade(short _validade);
		//sobrecarga
		//friend double operator+ (Produto const &t1, Produto const &t2);
	private:
		std::ostream& print(std::ostream &o) const;
	};

	#endif
