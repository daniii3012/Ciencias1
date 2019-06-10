#ifndef PILA1_H
#define PILA1_H
#include <iostream>
using namespace std;

class Pila{ 
	char *pila;
  	int p;
	public:
  	Pila (int max=100){
	  	pila = new char[max]; 
		p=0;
	}
	~Pila(){
		delete pila;
	}
	inline void meter (char v){
		pila[p++]=v;
	}
	inline char sacar(){
		return pila [--p];
	}
	inline int vacia(){
		return !p;
	} 
};


#endif
