/*
	Daniel Alejandro Montiel - 20171020049
	Angie Gabriela Antolinez - 20151020061
*/
#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>
#include "pila.h"
#include "cola.h"

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
		int get_raiz();
		int buscar(int raiz, int d);
		void inorden();
		void preorden();
		void posorden();
		void niveles();
		int min(int raiz);
		int eliminar(int raiz, int d);
		void imprimir();
		
};

void arbolBin::insertar(int d){
	int aux = 1;
	int j = 0;
	int cont = 0;
	int pos = arbol[0].der;
	arbol[pos].dato = d;
	arbol[pos].izq = 0;	
	arbol[pos].der = 0;
	
	// Actualiza el valor de las posiciones libres en cada posicion
	for(int i = 1; i < tam; i++){
		if(arbol[i].dato != NULL){
			cont++;
		}
		if(arbol[i].dato == NULL){
			arbol[j].der = i;
			j = i;
		}
	}
	
	// Asigna los hijos de cada posicion
	for(int i = 1; i < tam; i++){
		if(arbol[pos].dato >= arbol[aux].dato && aux != pos){
			if(arbol[aux].der != 0){
				aux = arbol[aux].der;
			}else if(arbol[aux].der == 0){
				arbol[aux].der = pos;
				break;
			}
		}else if(arbol[pos].dato < arbol[aux].dato && aux != pos){
			if(arbol[aux].izq != 0){
				aux = arbol[aux].izq;
			}else if(arbol[aux].izq == 0){
				arbol[aux].izq = pos;
				break;
			}
		}
	}
	
	// Posiciones libres = 0
	if(cont == tam-1){
		arbol[0].der = 0;
	}
	
	// Asignacion de la raiz en la posicion de control
	if(cont == 1){
		for(int i = 0; i < tam; i++){
			if(arbol[i].dato != NULL){
				arbol[0].izq = i;
			}
		}
	}
}

int arbolBin::get_raiz(){
	return arbol[0].izq;
}

int arbolBin::buscar(int raiz, int d){
	if(raiz == 0 || arbol[raiz].dato == d){
		//return arbol[raiz].dato;
		return raiz;
	}
	
	if(d > arbol[raiz].dato){
		return buscar(arbol[raiz].der, d);
	}else{
		return buscar(arbol[raiz].izq, d);
	}
}

void arbolBin::inorden(){
	Pila stack(50);
	int raiz = arbol[0].izq;
	int aux = raiz;
	
	while(stack.vacia() == 0 || aux != 0){
		while (aux != 0){ 
        	stack.meter(aux); 
        	aux = arbol[aux].izq; 
    	}
		aux = stack.sacar();
    	cout << arbol[aux].dato << " "; 
    	aux = arbol[aux].der; 
	}
}

void arbolBin::preorden(){
	Pila stack(50);
	int raiz = arbol[0].izq;
	int aux = raiz;
	stack.meter(raiz);
	
	while(stack.vacia() == 0){
		aux = stack.sacar();
		cout << arbol[aux].dato << " ";
		if(arbol[aux].der != 0){
			stack.meter(arbol[aux].der);
		}
		if(arbol[aux].izq != 0){
			stack.meter(arbol[aux].izq);
		}
	}
}

void arbolBin::posorden(){
	Pila stack1(50), stack2(50);
	int raiz = arbol[0].izq;
	int aux = raiz;
	stack1.meter(raiz);
	
	while(stack1.vacia() == 0){
		aux = stack1.sacar();
		stack2.meter(aux);
		if(arbol[aux].izq != 0){
			stack1.meter(arbol[aux].izq);
		}
		if(arbol[aux].der != 0){
			stack1.meter(arbol[aux].der);
		}
	}
	
	while(stack2.vacia() == 0){
		aux = stack2.sacar();
		cout << arbol[aux].dato << " ";
	}
}

void arbolBin::niveles(){
	cola_doble<int> p;
	int raiz = arbol[0].izq;
	int aux = raiz;
	p.enqueue(raiz);
	p.enqueue(NULL);
	
	while(p.get_tam() > 1){
		aux = p.dequeue();
		if(aux == NULL){
			p.enqueue(NULL);
			cout << endl;
		}else{
			if(arbol[aux].izq != 0){
				p.enqueue(arbol[aux].izq);
			}
			if(arbol[aux].der != 0){
				p.enqueue(arbol[aux].der);
			}
			cout << arbol[aux].dato << " ";
		}
	}
}

int arbolBin::min(int raiz){
	int aux = raiz;
	while(aux != 0 && arbol[aux].izq != 0){
		aux = arbol[aux].izq;
	}
	return aux;
}

int arbolBin::eliminar(int raiz, int d){
	int aux;
	int j = 0;
	int cont = 0;
	
	/*
	if(raiz == 0){
		//return raiz;
	}
	if(d < arbol[raiz].dato){
		cout << "Control 1 " << raiz << endl;
		arbol[raiz].izq = eliminar(arbol[raiz].izq, d);
	}else if(d > arbol[raiz].dato){
		cout << "Control 2 " << raiz << endl;
		arbol[raiz].der = eliminar(arbol[raiz].der, d);
	}else{
		cout << "Control 3" << raiz << endl;
		
		if(arbol[raiz].izq == 0){
			//return arbol[raiz].der;
			cout << "Delete izq" << endl;
		}else if(arbol[raiz].der == 0){
			//return arbol[raiz].izq;
			cout << "Delete der" << endl;
		}
			
		aux = min(arbol[raiz].der);
		cout << "Aux: " << aux << endl;
		arbol[raiz].dato = arbol[aux].dato;
		arbol[raiz].der = eliminar(arbol[raiz].der, arbol[aux].dato);
	}
	//return raiz;
	*/
	
	// Actualiza el valor de las posiciones libres en cada posicion
	for(int i = 1; i < tam; i++){
		if(arbol[i].dato != NULL){
			cont++;
		}
		if(arbol[i].dato == NULL){
			arbol[j].der = i;
			j = i;
		}
	}
	// Posiciones libres = 0
	if(cont == tam-1){
		arbol[0].der = 0;
	}
	// Asignacion de la raiz en la posicion de control
	if(cont == 1){
		for(int i = 0; i < tam; i++){
			if(arbol[i].dato != NULL){
				arbol[0].izq = i;
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
	cout << endl;
}

#endif
