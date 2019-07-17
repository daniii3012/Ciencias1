/*
	Daniel Alejandro Montiel - 20171020049
	Angie Gabriela Antolinez - 20151020061
	
*/

#include <iostream>
#include "lista.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Ing{
	string nom, medida;
	int cantidad;
};

template <class T>
struct Postre{
	lista<T> ing;
	string nombre, procedimiento, tipo;
	int tiempo;	
};



int main(int argc, char** argv) {
	
	int tam1, tam2, numI, tiempo, cant, opc, pos;
	string nomP, nomI, proc, tipo, med;
	
	lista< Postre<Ing> > lista_postres;
	Ing ingre;
	Postre<Ing> postre;
	
	while(opc != 4){
		cout << "1) Ingresar Postre" << endl;
		cout << "2) Ver Postres" << endl;
		cout << "3) Borrar Postre" << endl;
		cout << "4) Salir" << endl;
		cin >> opc;	
		switch(opc){
			case 1:
				system("cls");
				cout << "Nombre del postre: ";
				cin >> nomP;
				postre.nombre = nomP;
				
				cout << "Procedimiento: ";
				cin >> proc;
				postre.procedimiento = proc;
				
				cout << "Tipo: ";
				cin >> tipo;
				postre.tipo = tipo;
				
				cout << "Tiempo: ";
				cin >> tiempo;
				postre.tiempo = tiempo;
				
				cout << "Numero de ingredientes: ";
				cin >> numI;
				
				for(int i = 0; i < numI; i++){
					cout << "Nombre del ingrediente " << (i + 1) << ": ";
					cin >> nomI;
					ingre.nom = nomI;
					
					cout << "Cantidad: ";
					cin >> cant;
					ingre.cantidad = cant;
					
					cout << "Medida: ";
					cin >> med;
					ingre.medida = med;
					
					postre.ing.insertar_inicio(ingre);
				}
				
				lista_postres.insertar_inicio(postre);
				
				break;
			case 2:
				system("cls");
				tam1 = lista_postres.get_tam();
				
				for(int i = 1; i <= tam1; i++){
					tam2 = lista_postres.buscar(i).ing.get_tam();
					cout << i << ". Postre: ";
					cout << lista_postres.buscar(i).nombre << endl;
					cout << "           " << lista_postres.buscar(i).procedimiento << endl;
					cout << "           " << lista_postres.buscar(i).tipo << endl;
					cout << "           " << lista_postres.buscar(i).tiempo << endl;
					cout << "   Ingredientes: ";
					for(int j = 1; j <= tam2; j++){
						cout << lista_postres.buscar(i).ing.buscar(j).nom << " ";
						cout << lista_postres.buscar(i).ing.buscar(j).cantidad << " ";
						cout << lista_postres.buscar(i).ing.buscar(j).medida << " ";
						cout << endl << "                 ";
					}
					cout<<endl;
				}
				
				break;
			case 3:
				system("cls");
				
				cout << "Numero del postre a borrar: ";
				cin >> pos;
				
				lista_postres.borrar_nodo(pos);
				
				break;
		}
	}
	
	
	return 0;
}
