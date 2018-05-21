#ifndef _BEBIDA_H_
#define _BEBIDA_H_

#include "produto.h"

class Bebida : public Produto
{
public:
  Bebida();
  Bebida(std::string _codigo, std::string _descricao, short _preco,
    short _teor);
    ~Bebida();
  private:
    short m_teor;
  public:
    // getters

    // setters

    //sobrecarga
    friend double operator+ (Produto const &t1, Produto const &t2);
    friend std::ostream& operator<< (std::ostream &o, Produto const &t);
  private:
    std::ostream& print(std::ostream &o) const;
  };

  #endif
