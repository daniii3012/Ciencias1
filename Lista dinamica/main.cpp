#include <iostream>
#include "lista.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	lista<int> x;
	lista<float> y;
	lista<char> z;
	
	x.insertar_nodo(1, 6);
	x.insertar_nodo(2, 4);
	x.insertar_nodo(3, 0);	
	x.imprimir();
	//cout << x.get_tam() << endl;
	
	x.insertar_nodo(1, 8);
	x.insertar_nodo(4, 2);
	x.imprimir();
	
	return 0;
}
