#include <iostream>
#include "lista.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	lista<int> x;
	lista<float> y;
	lista<char> z;
	
	cout << "Lista de int: ";
	x.insertar_nodo(1, 6);
	x.insertar_nodo(2, 4);
	x.insertar_nodo(3, 0);	
	x.imprimir();
	//cout << x.get_tam() << endl;
	cout << "Lista de int: ";
	x.insertar_nodo(1, 9);
	x.insertar_nodo(4, 2);
	x.imprimir();
	cout << "Lista de int: ";
	x.cambiar(1, 8);
	x.imprimir();
	cout << "Lista de int: ";
	x.borrar_nodo(2);
	x.imprimir();
	cout<<"El número buscado es: "<<x.buscar(3);
	cout << endl;
	cout << endl;
	
	cout << "Lista de float: ";
	y.insertar_nodo(1, 7.8);
	y.insertar_nodo(1, 4.5);
	y.insertar_nodo(3, 1.1);
	y.cambiar(3, 1.2);
	y.imprimir();
	y.lista_vacia();
	cout << endl;
	
	cout << "Lista de char: ";
	z.insertar_nodo(1, 'C');
	z.insertar_nodo(1, 'B');
	z.insertar_nodo(1, 'A');
	z.imprimir();
		
	return 0;
}
