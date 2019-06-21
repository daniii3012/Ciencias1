/*
	Daniel Alejandro Montiel - 20171020049
	Angie Gabriela Antolinez - 20151020061
*/
#include <iostream>
#include "arbol.h"

using namespace std;

int main(int argc, char** argv) {
	
	arbolBin arbol(9);
	arbol.imprimir();
	
	arbol.insertar(100);
	cout << endl;
	arbol.imprimir();
	
	arbol.insertar(90);
	cout << endl;
	arbol.imprimir();
	
	arbol.insertar(80);
	cout << endl;
	arbol.imprimir();
	
	arbol.insertar(110);
	cout << endl;
	arbol.imprimir();
	
	arbol.insertar(120);
	cout << endl;
	arbol.imprimir();
	
	arbol.insertar(95);
	cout << endl;
	arbol.imprimir();
	
	arbol.insertar(130);
	cout << endl;
	arbol.imprimir();
	
	arbol.insertar(105);
	cout << endl;
	arbol.imprimir();
	
	return 0;
}
