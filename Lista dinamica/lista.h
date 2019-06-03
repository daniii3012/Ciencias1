//Directrices del pre-procesador

#ifndef LISTA_H
#define LISTA_H
//Contenido de la libreria
#include <iostream>
using namespace std;

template <class T> // o template <typename T>

struct nodo{
	T dato;
	nodo <T> *sig;
};


template <class T>

class lista{
	nodo <T> *cab;
	int tam;
		
	public: lista(){
		cab = NULL;
		tam = 0;	
	}
	
	void insertar_nodo(int pos, T d);
	void insertar_final(T d);
	void insertar_inicio(T d);
	void borrar_nodo(int pos);
	T buscar(int pos);
	T cambiar(int pos, T d);
	int get_tam();
	void imprimir();
};


template <class T>

int lista<T>::get_tam(){
	int cont = 1;
	
	nodo <T> *aux;
	aux = cab;
	
	while(aux != NULL){
		aux = aux -> sig;
		cont++;
	}
	
	return cont;
}


template <class T>

T lista<T>::cambiar(int pos, T d){
	int cont = 1;
	
	nodo <T> *aux;	
	aux = cab;
	
	while(cont < pos - 1 && aux != NULL){
		aux = aux -> sig;
		cont++;
	}
	
	aux -> dato = d;
}


template <class T>

void lista<T>::insertar_nodo(int pos, T d){
	int tam = get_tam();
	int cont;
	
	if(pos > tam){
		insertar_final(d);
	}else if(pos == 1){
		insertar_inicio(d);
	}else{
		nodo <T> *nuevo, *aux;
		nuevo = new nodo <T>;
		nuevo -> dato = d;
		
		aux = cab;
		cont = 1;
		
		while(cont < pos - 1 && aux != NULL){
			aux = aux -> sig;
			cont++;
		}
		
		nuevo -> sig = aux -> sig;
		aux -> sig = nuevo;
		tam++;
	}
}


template <class T>

void lista<T>::insertar_final(T d){
	int tam = get_tam();
	int cont = 1;
	
	nodo <T> *nuevo, *aux;
	nuevo = new nodo <T>;
	nuevo -> dato = d;
	nuevo -> sig = NULL;
	
	aux = cab;
	
	while(cont < tam && aux != NULL){
		aux = aux -> sig;
		cont++;
	}
	
	aux -> sig = nuevo;
	tam++;
}


template <class T>

void lista<T>::insertar_inicio(T d){
	int tam = get_tam();
	
	nodo <T> *nuevo;
	nuevo = new nodo <T>;
	nuevo -> dato = d;
	
	nuevo -> sig = cab;
	cab = nuevo;
	tam++;
}


template <class T>

void lista<T>::imprimir(){
	nodo <T> *aux;
	aux = cab;
    cout << "Lista: ";
    while (aux != NULL)
    {
        cout << aux -> dato << " ";
        aux = aux -> sig;
    }
    cout << endl;
}

#endif
