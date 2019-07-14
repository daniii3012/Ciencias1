#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "lista.h"

using namespace std;

struct Sucursal{
	string nombre_sucursal;
	string nombre_gerente;
	string localidad;
	
	string calle_inicio;
	string carrera_inicio;
	string calle_fin;
	string carrera_fin;
	
	//int num_paseadores;
	//int num_clientes;
};

struct Paseador{
	string sucursal;
	string nombre;
	string apellido;
	string tipo_id;
	int id;
	string sexo;
	int tel_fijo;
	int tel_celular;
	string e_mail;
	
	int dia_nacimiento;
	int mes_nacimiento;
	int ano_nacimiento;
	
	string ciudad_nacimiento;
	string pais_nacimiento;
	string direccion;
	string barrio;
	string horario;
};

struct Perro{
	string nombre;
	
	int dia_nacimiento;
	int mes_nacimiento;
	int ano_nacimiento;
	
	string raza;
	string tamano;
	string concentrado;
};

template <class T>
struct Cliente{
	string nombre;
	string apellido;
	int id;
	string sexo;
	string localidad_residencia;
	
	lista<T> perros;
};

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
