#include <iomanip>
#include "roupa.h"

Roupa::Roupa() {}

Roupa::Roupa(std::string _codigo, std::string _descricao, short _preco,
  std::string _marca, std::string _sexo, std::string _tamanho):
	Produto(_codigo, _descricao, _preco),marca(_marca), sexo(_sexo), tamanho(_tamanho) {}

Roupa::~Roupa() {}

std::ostream&
Roupa::print(std::ostream &o) const {
	o << std::setfill (' ') << std::setw (10) << m_cod_barras << " | "
		<< std::setfill ('.') << std::setw (20) << m_descricao << " | "
		<< std::setfill (' ') << std::setw (5) << m_preco << " | "
    << std::setfill (' ') << std::setw (5) << marca << " | "
    << std::setfill (' ') << std::setw (5) << sexo << " | "
    << std::setfill (' ') << std::setw (5) << tamanho << " | "<<std::endl;
	return o;
}
