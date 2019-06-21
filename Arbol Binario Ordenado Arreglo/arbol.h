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

class arbol{
	arbol_array *arbolBin;
	int tam;
	public:
		arbol(int n){
			tam = n;
			int i;
			arbolBin = new arbol_array[tam];
			
			for(i = 0; i < tam; i++){
				arbolBin[i].dato = NULL;
				arbolBin[i].izq = 0;
				arbolBin[i].der = 0;
			}
			
			for(i = 0; i < tam-1; i++){
				arbolBin[i].der = i+1;
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

void arbol::insertar(int d){
	
}

void arbol::imprimir(){
	for(int i = 0; i < tam; i++){
		cout << "Dato: " << arbolBin[i].dato << " ";
		cout << "Izq: " << arbolBin[i].izq << " ";
		cout << "Der: " << arbolBin[i].der << " ";
		cout << endl;
	}
}

#endif
