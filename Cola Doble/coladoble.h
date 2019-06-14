/*
	Daniel Alejandro Montiel - 20171020049
	Angie Gabriela Antolinez - 20151020061
*/
#ifndef LISTA_H
#define LISTA_H
#include <iostream>
using namespace std;

template <class T>

struct nodo{
	T dato;
	nodo <T> *ant, *sig;
};


template <class T>

class cola_doble{
	
	nodo <T> *cab_izq, *cab_der, *fin_izq, *fin_der;
	
	int tam;
		
	public: cola_doble(){
		cab_izq = NULL;
		cab_der = NULL;
		fin_izq = NULL;
		fin_der = NULL;
		tam = 0;	
	}
	void enqueue(T d, char pos);
	void dequeue(char pos);
	bool cola_doble_vacia();
	int get_tam();
	//void imprimir();
};

cola_doble::cola_doble(){ 
	cab_izq = new nodo;
	cab_der = new nodo;
	fin_izq = cab_der;
	fin_der = cab_izq;
	
	cab_izq -> sig = fin_izq;
	cab_izq -> ant = NULL;
	cab_izq = fin_der;
	
	cab_der -> sig = NULL;
	cab_der -> ant = fin_der;
	cab_der = fin_izq;
}


template <class T>

int cola_doble<T>::get_tam(){
	int cont = 0;	
	nodo <T> *aux;
	aux = cab_izq;
	
	while(aux != NULL){
		aux = aux -> sig;
		cont++;
	}
	
	return cont;
}


template <class T>

bool cola_doble<T>::lista_vacia(){
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
