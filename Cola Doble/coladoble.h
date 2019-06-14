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
			cab = new nodo <T>;
			fin = new nodo <T>;
			
			cab -> sig = fin;
			cab -> ant = NULL;
			
			fin -> sig = NULL;
			fin -> ant = cab;
			tam = 0;	
		}
	void enqueue(T d, char pos);
	T dequeue(char pos);
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
void cola_doble<T>::enqueue(T d, char pos )
{
	nodo <T> *nuevo;
	nuevo = new nodo <T>;
	nuevo -> dato = d;
	if (pos=='I'){
		nuevo->sig=fin;
		nuevo->ant= fin->ant;
		fin->ant->sig=nuevo;
		fin->ant=nuevo;
	}
	else{
		nuevo->ant=cab;
		nuevo->sig=cab->sig;
		cab->sig->ant=nuevo;
		cab->sig=nuevo;
	}
}
template <class T>
void cola_doble<T>::imprimir(){
	    nodo<T> *aux;
    aux = cab->sig;
    while(aux !=fin ){
    	cout<<aux->dato<<" ";
    	aux = aux->sig;
	} 
}






template <class T>

int cola_doble<T>::get_tam(){
	int cont = 0;	
	nodo <T> *aux;
	aux = cab -> sig;
	
	while(aux != fin){
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

T cola_doble<T>::dequeue(char pos){	
	nodo <T> *aux;
	T d;

	if(!cola_doble_vacia()){
		if(pos == 'izq'){
			aux = cab -> sig;
			d = aux -> dato;
			cab -> sig = aux -> sig;
			aux -> sig -> ant = cab;
			delete aux;
			tam--;
		} else if (pos == 'der'){
			aux = fin -> ant;
			d = aux -> dato;
			fin -> ant = aux -> ant;
			aux -> ant -> sig = fin;
			delete aux;
			tam--;
		}
	}
}

#endif
