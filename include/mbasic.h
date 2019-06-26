#ifndef _MBASIC_H_
#define _MBASIC_H_

	/**
       * Namespace para a classe MathBasic.
       * para organização e para evitar colisão de nomes de classes.
   */
namespace mbasic{

	/**
       * Classe MathBasic.
       * classe que realiza operações de adição, subitração, multiplicação, e divisão
       * de forma genérica utilizando template.
   */
  class MathBasic{
  public:
  	/**
       * Adição.
       * realiza operação de Adição
   */
  	template<typename T>
     static T add(T a, T b){
        return a + b;
    }
    	/**
       * Subitração.
       * realiza operação de Subtração 
   */
 	template<typename T>    
     static T dif(T a, T b){
        return a - b;
    }
    	/**
       * Classe Multiplicação.
       * realiza operação de Multiplicação
   */
    template<typename T>  
     static T mux(T a, T b){
        return a * b;
    }
	/**
       * Divisão.
       * realiza operação de Divisão
   */
 	template<typename T>    
     static T div(T a, T b){
        return a / b;
    }
  };
}
  #endif

