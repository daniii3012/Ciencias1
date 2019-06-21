/*
	Daniel Alejandro Montiel - 20171020049
	Angie Gabriela Antolinez - 20151020061
*/
#include <iostream>
#include "arbol.h"

using namespace std;

int main(int argc, char** argv) {
	int num;
	arbolBin arbol(9);
	
	arbol.insertar(100);
	arbol.insertar(90);
	arbol.insertar(80);
	arbol.insertar(110);
	arbol.insertar(120);
	arbol.insertar(95);
	arbol.insertar(130);
	arbol.insertar(105);
	arbol.imprimir();
	
	// Buscar
	cout << "Buscar: ";
	cin >> num;
	cout << "Busqueda en la posicion: " << arbol.buscar(arbol.get_raiz(), num) << endl;
	
	cout << endl << "Inorden: ";
	arbol.inorden();
	cout << endl;
	
	cout << endl << "Preorden: ";
	arbol.preorden();
	cout << endl;
	
	cout << endl << "Posorden: ";
	arbol.posorden();
	cout << endl;
	
	cout << endl << "Niveles: " << endl;;
	arbol.niveles();
	
	return 0;
}
