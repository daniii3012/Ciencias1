/*
	Daniel Alejandro Montiel - 20171020049
	Angie Gabriela Antolinez - 20151020061
*/
#include <iostream>
#include "arbol.h"

using namespace std;

int main(int argc, char** argv) {
	
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
	
	return 0;
}
