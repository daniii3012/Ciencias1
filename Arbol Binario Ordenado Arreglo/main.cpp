/*
	Daniel Alejandro Montiel - 20171020049
	Angie Gabriela Antolinez - 20151020061
*/
#include <iostream>
#include "arbol.h"

using namespace std;

int main(int argc, char** argv) {
	
	arbol arbolBin(4);
	
	arbolBin.imprimir(); 
	arbolBin.insertar(100);
	
	cout << endl;
	
	arbolBin.imprimir(); 
	
	return 0;
}
