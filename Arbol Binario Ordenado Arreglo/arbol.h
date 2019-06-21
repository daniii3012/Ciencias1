/*
	Daniel Alejandro Montiel - 20171020049
	Angie Gabriela Antolinez - 20151020061
*/
#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>

using namespace std;


struct arbol_array{
	int dato;
	int izq;
	int der;	
};

class arbolBin{
	arbol_array *arbol;
	int tam;
	public:
		arbolBin(int n){
			tam = n;
			int i;
			arbol = new arbol_array[tam];
			
			for(i = 0; i < tam; i++){
				arbol[i].dato = NULL;
				arbol[i].izq = NULL;
				arbol[i].der = NULL;
			}
			
			for(i = 0; i < tam-1; i++){
				arbol[i].der = i+1;
			}
		}
		void insertar(int d);
		bool buscar(int d);
		void inorden();
		void preorden();
		void posorden();
		void niveles();
		void eliminar(int d);
		void imprimir();
		
};

void arbolBin::insertar(int d){
	int j = 0;
	int raiz = 0;
	int pos = arbol[0].der;
	arbol[pos].dato = d;
	arbol[pos].izq = 0;	
	arbol[pos].der = 0;
	
	
	for(int i = 1; i < tam; i++){
		if(arbol[i].dato != NULL){
			raiz++;
		}
		if(arbol[i].dato == NULL){
			arbol[j].der = i;
			j++;
		}
	}
	
	// Asignacion de la raiz en la posicion de control
	if(raiz == 1){
		for(int k = 0; k < tam; k++){
			if(arbol[k].dato != NULL){
				arbol[0].izq = k;
			}
		}
	}
}

void arbolBin::imprimir(){
	for(int i = 0; i < tam; i++){
		cout << i << " Dato: " << arbol[i].dato << " ";
		cout << "Izq: " << arbol[i].izq << " ";
		cout << "Der: " << arbol[i].der << " ";
		cout << endl;
	}
}

#endif
