//  /$$$$$$$                                                     /$$                      /$$$$$$  /$$                               /$$                    
// | $$__  $$                                                   | $$                     /$$__  $$|__/                              |__/                    
// | $$  \ $$ /$$$$$$   /$$$$$$  /$$   /$$  /$$$$$$   /$$$$$$$ /$$$$$$    /$$$$$$       | $$  \__/ /$$  /$$$$$$  /$$$$$$$   /$$$$$$$ /$$  /$$$$$$   /$$$$$$$
// | $$$$$$$//$$__  $$ /$$__  $$| $$  | $$ /$$__  $$ /$$_____/|_  $$_/   /$$__  $$      | $$      | $$ /$$__  $$| $$__  $$ /$$_____/| $$ |____  $$ /$$_____/
// | $$____/| $$  \__/| $$  \ $$| $$  | $$| $$$$$$$$| $$        | $$    | $$  \ $$      | $$      | $$| $$$$$$$$| $$  \ $$| $$      | $$  /$$$$$$$|  $$$$$$ 
// | $$     | $$      | $$  | $$| $$  | $$| $$_____/| $$        | $$ /$$| $$  | $$      | $$    $$| $$| $$_____/| $$  | $$| $$      | $$ /$$__  $$ \____  $$
// | $$     | $$      |  $$$$$$/|  $$$$$$$|  $$$$$$$|  $$$$$$$  |  $$$$/|  $$$$$$/      |  $$$$$$/| $$|  $$$$$$$| $$  | $$|  $$$$$$$| $$|  $$$$$$$ /$$$$$$$/
// |__/     |__/       \______/  \____  $$ \_______/ \_______/   \___/   \______/        \______/ |__/ \_______/|__/  |__/ \_______/|__/ \_______/|_______/ 
//                               /$$  | $$                                                                                                                  
//                              |  $$$$$$/                                                                                                                  
//                               \______/  
// 
// Angie Gabriela Antolinez - 20151020061                                                                                                                 
// Daniel Alejandro Montiel - 20171020049
	
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "lista.h"
#include "sucursal.h"

using namespace std;

int main(int argc, char** argv) {
	
	int i, j;
	string nom_sucursal, nom_gerente, localidad, cll_inicio, cr_inicio, cll_fin, cr_fin;
	
	Sucursal sucursal;	
	lista<Sucursal> lista_sucursales;
	
	ifstream archEntrada("sucursales.txt", ios::in);
 	
 	//ofstream archsalida1("sucursales.txt", ios::out|ios::trunc);

 	if (!archEntrada.good()){
	 	cerr << "No se pudo abrir el archivo" << endl;
    	exit(1);
	}
	/*
 	if (!archsalida1.good()){
	 	cerr << "No se pudo abrir el archivo" << endl;
    	exit(1);
	}
	*/
	// lectura del archivo y creaci?n del arreglo   
 	while(!archEntrada.eof()){
    	archEntrada >> nom_sucursal;
    	sucursal.nombre_sucursal = nom_sucursal;
    	
    	archEntrada >> nom_gerente;
    	sucursal.nombre_gerente = nom_gerente;
    	
    	archEntrada >> localidad;
    	sucursal.localidad = localidad;
    	
    	archEntrada >> cll_inicio;
    	sucursal.calle_inicio = cll_inicio;
    	
    	archEntrada >> cr_inicio;
    	sucursal.carrera_inicio = cr_inicio;
    	
    	archEntrada >> cll_fin;
    	sucursal.calle_fin = cll_fin;
    	
    	archEntrada >> cr_fin;
    	sucursal.carrera_fin = cr_fin;
    	
    	lista_sucursales.insertar_inicio(sucursal);
    	
    	i++;
   	}
   	
	archEntrada.close();
	
	j = lista_sucursales.get_tam();
	for(i = 1; i <= j; i++){
		cout << lista_sucursales.buscar(i).nombre_sucursal << " ";
		cout << lista_sucursales.buscar(i).nombre_gerente << " ";
		cout << lista_sucursales.buscar(i).localidad << " ";
		cout << lista_sucursales.buscar(i).calle_inicio << " ";
		cout << lista_sucursales.buscar(i).carrera_inicio << " ";
		cout << lista_sucursales.buscar(i).calle_fin << " ";
		cout << lista_sucursales.buscar(i).carrera_fin << " ";
		cout << endl;
	}
	
	return 0;
}
