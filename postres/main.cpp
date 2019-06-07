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
	
	int tam1, tam2;
	
	lista< Postre<Ing> > lista_postres;
	
	Ing ingre;
	ingre.nom = "Azucar";
	ingre.cantidad = 10;
	ingre.medida = "gr";
	
	Postre<Ing> postre;
	postre.nombre = "Fresas con crema";
	postre.procedimiento = "Mezcla";
	postre.tipo = "Condensado";
	postre.tiempo = 7;
	postre.ing.insertar_inicio(ingre);
	
	lista_postres.insertar_inicio(postre);
	
	tam1 = lista_postres.get_tam();
	tam2 = lista_postres.buscar(1).ing.get_tam();
	
	for(int i = 1; i <= tam1; i++){
		cout<<lista_postres.buscar(i).nombre<<endl;
		cout<<lista_postres.buscar(i).procedimiento<<endl;
		cout<<lista_postres.buscar(i).tipo<<endl;
		cout<<lista_postres.buscar(i).tiempo<<endl;
		for(int j = 1; j <= tam2; j++){
			cout<<lista_postres.buscar(i).ing.buscar(j).nom;
			cout<<lista_postres.buscar(i).ing.buscar(j).cantidad;
			cout<<lista_postres.buscar(i).ing.buscar(j).medida;
		}
	}
	//lista_postres.imprimir();
	
	
	
	
	return 0;
}
