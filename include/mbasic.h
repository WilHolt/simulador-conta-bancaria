#ifndef _MBASIC_H_
#define _MBASIC_H_


namespace mbasic{


  class MathBasic{
  public:
  	template<typename T>
     static T add(T a, T b){
        return a + b;
    }
 	template<typename T>    
     static T dif(T a, T b){
        return a - b;
    }
    template<typename T>  
     static T mux(T a, T b){
        return a * b;
    }

 	template<typename T>    
     static T div(T a, T b){
        return a / b;
    }
  };
}
  #endif

