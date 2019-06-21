/*
	Daniel Alejandro Montiel - 20171020049
	Angie Gabriela Antolinez - 20151020061
*/
#include <iostream>
#include "arbol.h"

using namespace std;

int main(int argc, char** argv) {
	
	arbolBin arbol(4);
	
	arbol.imprimir(); 
	arbol.insertar(100);
	cout << endl;
	arbol.imprimir();
	
	arbol.insertar(50);
	cout << endl;
	arbol.imprimir();
	
	arbol.insertar(150);
	cout << endl;
	arbol.imprimir();
	
	return 0;
}
