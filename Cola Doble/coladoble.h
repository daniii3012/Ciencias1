/*
	Daniel Alejandro Montiel - 20171020049
	Angie Gabriela Antolinez - 20151020061
*/
#ifndef COLADOBLE_H
#define COLADOBLE_H
#include <iostream>
using namespace std;

template <class T>

struct nodo{
	T dato;
	nodo <T> *ant, *sig;
};


template <class T>

class cola_doble{
	
	nodo <T> *cab, *fin;
	
	int tam;
		
	public: 
		cola_doble(){
			cab -> sig = fin;
			cab -> ant = NULL;
			
			fin -> sig = NULL;
			fin -> ant = cab;
			tam = 0;	
		}
	void enqueue(T d, char pos);
	void dequeue(char pos);
	bool cola_doble_vacia();
	int get_tam();
	//void imprimir();
};
/*
cola_doble::cola_doble(){ 
	cab = new nodo;
	fin = new nodo;
	
	cab -> sig = fin;
	cab -> ant = NULL;
	
	fin -> sig = NULL;
	fin -> ant = cab;
}
*/

template <class T>

int cola_doble<T>::get_tam(){
	int cont = 0;	
	nodo <T> *aux;
	aux = cab;
	
	while(aux != NULL){
		aux = aux -> sig;
		cont++;
	}
	
	return cont;
}


template <class T>

bool cola_doble<T>::cola_doble_vacia(){
	int tam = get_tam();
	if(tam == 0){
		return true;
	} else {
		return false;
	}
}


template <class T>

void cola_doble<T>::dequeue(char pos){
	
}

#endif
