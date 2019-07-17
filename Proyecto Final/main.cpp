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
// Proyecto Elaborado por:
// Angie Gabriela Antolinez - 20151020061                                                                                                                 
// Daniel Alejandro Montiel - 20171020049
	
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "lista.h"
#include "sucursal.h"
#include "paseador.h"
#include "cliente.h"

using namespace std;

// Declaracion de variables

int pos_save = 0;
bool modificar = false;
long long tel_celular, id;
int tam_sucursales, tam_paseadores, tam_clientes, tam_perros;
int num_paseadores, num_clientes, num_perros;
int	dia_nacimiento, mes_nacimiento, ano_nacimiento;
int tel_fijo, h_entrada, h_salida;
int cll_inicio, cr_inicio, cll_fin, cr_fin;
string nombre, apellido, tipo_id, sexo, e_mail;
string ciudad_nacimiento, pais_nacimiento, dir_paseador, localidad_paseador;
string raza, tamano, concentrado;
string nom_sucursal, nom_gerente, localidad;

// Lectura de sucursales y creacion de la lista sucursales
void read_file_sucursales(lista<Sucursal>& lista_sucursales, Sucursal& sucursal){
	ifstream file_in_sucursales("sucursales.txt", ios::in);
 	if (!file_in_sucursales.good()){
	 	cerr << "No se pudo abrir el archivo" << endl;
    	exit(1);
	}	 
 	while(!file_in_sucursales.eof()){
    	file_in_sucursales >> nom_sucursal;
    	sucursal.nombre_sucursal = nom_sucursal;
    	file_in_sucursales >> nom_gerente;
    	sucursal.nombre_gerente = nom_gerente;
    	file_in_sucursales >> localidad;
    	sucursal.localidad = localidad;
    	file_in_sucursales >> cll_inicio;
    	sucursal.calle_inicio = cll_inicio;
    	file_in_sucursales >> cr_inicio;
    	sucursal.carrera_inicio = cr_inicio;
    	file_in_sucursales >> cll_fin;
    	sucursal.calle_fin = cll_fin;
    	file_in_sucursales >> cr_fin;
    	sucursal.carrera_fin = cr_fin;
    	file_in_sucursales >> num_paseadores;
    	sucursal.num_paseadores = num_paseadores;
    	file_in_sucursales >> num_clientes;
    	sucursal.num_clientes = num_clientes;
    	lista_sucursales.insertar_inicio(sucursal);
   	}
	file_in_sucursales.close();
}

// Lectura de los paseadores y creacion de la lista de paseadores
void read_file_paseadores(lista<Paseador>& lista_paseadores, Paseador& paseador){
	ifstream file_in_paseadores("paseadores.txt", ios::in);
 	if (!file_in_paseadores.good()){
	 	cerr << "No se pudo abrir el archivo" << endl;
    	exit(1);
	}
	while(!file_in_paseadores.eof()){
    	file_in_paseadores >> nom_sucursal;
    	paseador.sucursal = nom_sucursal;
    	file_in_paseadores >> nombre;
    	paseador.nombre = nombre;
    	file_in_paseadores >> apellido;
    	paseador.apellido = apellido;
    	file_in_paseadores >> tipo_id;
    	paseador.tipo_id = tipo_id;
    	file_in_paseadores >> id;
    	paseador.id = id;
    	file_in_paseadores >> sexo;
    	paseador.sexo = sexo;
    	file_in_paseadores >> tel_fijo;
    	paseador.tel_fijo = tel_fijo;
    	file_in_paseadores >> tel_celular;
    	paseador.tel_celular = tel_celular;
    	file_in_paseadores >> e_mail;
    	paseador.e_mail = e_mail;
    	file_in_paseadores >> dia_nacimiento;
    	paseador.dia_nacimiento = dia_nacimiento;
    	file_in_paseadores >> mes_nacimiento;
    	paseador.mes_nacimiento = mes_nacimiento;
    	file_in_paseadores >> ano_nacimiento;
    	paseador.ano_nacimiento = ano_nacimiento;
    	file_in_paseadores >> ciudad_nacimiento;
    	paseador.ciudad_nacimiento = ciudad_nacimiento;
    	file_in_paseadores >> pais_nacimiento;
    	paseador.pais_nacimiento = pais_nacimiento;
    	file_in_paseadores >> dir_paseador;
    	paseador.direccion = dir_paseador;
    	file_in_paseadores >> localidad_paseador;
    	paseador.localidad = localidad_paseador;
    	file_in_paseadores >> h_entrada;
    	paseador.hora_entrada = h_entrada;
    	file_in_paseadores >> h_salida;
    	paseador.hora_salida = h_salida;
    	paseador.num_perros = 0;
    	lista_paseadores.insertar_inicio(paseador);
   	}
   	file_in_paseadores.close();
}

// Lectura de clientes y creacion de la lista de clientes
void read_file_clientes(lista< Cliente<Perro> >& lista_clientes, Cliente<Perro>& cliente, Perro& perro){
   	ifstream file_in_clientes("clientes.txt", ios::in);
 	if (!file_in_clientes.good()){
	 	cerr << "No se pudo abrir el archivo" << endl;
    	exit(1);
	}
 	while(!file_in_clientes.eof()){
    	file_in_clientes >> nombre;
    	cliente.nombre = nombre;
    	file_in_clientes >> apellido;
    	cliente.apellido = apellido;
    	file_in_clientes >> id;
    	cliente.id = id;
    	file_in_clientes >> sexo;
    	cliente.sexo = sexo;
    	file_in_clientes >> localidad;
    	cliente.localidad_residencia = localidad;
    	file_in_clientes >> num_perros;
    	cliente.num_perros = num_perros;
    	for(int i = 0; i < num_perros; i++){
    		file_in_clientes >> id;
    		perro.id = id;
    		file_in_clientes >> nombre;
    		perro.nombre = nombre;
    		file_in_clientes >> mes_nacimiento;
    		perro.mes_nacimiento = mes_nacimiento;
    		file_in_clientes >> ano_nacimiento;
    		perro.ano_nacimiento = ano_nacimiento;
    		file_in_clientes >> raza;
    		perro.raza = raza;
    		file_in_clientes >> tamano;
    		perro.tamano = tamano;
    		file_in_clientes >> concentrado;
    		perro.concentrado = concentrado;
    		cliente.lista_perros.insertar_inicio(perro);
		}
    	lista_clientes.insertar_inicio(cliente);
   	}
	file_in_clientes.close();
}

// Escritura del archivo sucursales
void write_file_sucursales(lista<Sucursal> lista_sucursales){
	ofstream file_out_sucursales("sucursales.txt", ios::out|ios::trunc);
 	if (!file_out_sucursales.good()){
	 	cerr << "No se pudo abrir el archivo" << endl;
    	exit(1);
	}
	int tam_sucursales = lista_sucursales.get_tam();
	for(int i = 1; i <= tam_sucursales; i++){
		file_out_sucursales << lista_sucursales.buscar(i).nombre_sucursal << " ";
		file_out_sucursales << lista_sucursales.buscar(i).nombre_gerente << " ";
		file_out_sucursales << lista_sucursales.buscar(i).localidad << " ";
		file_out_sucursales << lista_sucursales.buscar(i).calle_inicio << " ";
		file_out_sucursales << lista_sucursales.buscar(i).carrera_inicio << " ";
		file_out_sucursales << lista_sucursales.buscar(i).calle_fin << " ";
		file_out_sucursales << lista_sucursales.buscar(i).carrera_fin << " ";
		file_out_sucursales << lista_sucursales.buscar(i).num_paseadores << " ";
		file_out_sucursales << lista_sucursales.buscar(i).num_clientes;
		if(tam_sucursales != i)
			file_out_sucursales << "\n";
	}
	file_out_sucursales.close();
}

// Escritura del archivo paseadores
void write_file_paseadores(lista<Paseador> lista_paseadores){
	ofstream file_out_paseadores("paseadores.txt", ios::out|ios::trunc);
	if (!file_out_paseadores.good()){
	 	cerr << "No se pudo abrir el archivo" << endl;
    	exit(1);
	}
	int tam_paseadores = lista_paseadores.get_tam();
	for(int i = 1; i <= tam_paseadores; i++){
		file_out_paseadores << lista_paseadores.buscar(i).sucursal << " ";
		file_out_paseadores << lista_paseadores.buscar(i).nombre << " ";
		file_out_paseadores << lista_paseadores.buscar(i).apellido << " ";
		file_out_paseadores << lista_paseadores.buscar(i).tipo_id << " ";
		file_out_paseadores << lista_paseadores.buscar(i).id << " ";
		file_out_paseadores << lista_paseadores.buscar(i).sexo << " ";
		file_out_paseadores << lista_paseadores.buscar(i).tel_fijo << " ";
		file_out_paseadores << lista_paseadores.buscar(i).tel_celular << "\n";
		file_out_paseadores << lista_paseadores.buscar(i).e_mail << " ";
		file_out_paseadores << lista_paseadores.buscar(i).dia_nacimiento << " ";
		file_out_paseadores << lista_paseadores.buscar(i).mes_nacimiento << " ";
		file_out_paseadores << lista_paseadores.buscar(i).ano_nacimiento << " ";
		file_out_paseadores << lista_paseadores.buscar(i).ciudad_nacimiento << " ";
		file_out_paseadores << lista_paseadores.buscar(i).pais_nacimiento << " ";
		file_out_paseadores << lista_paseadores.buscar(i).direccion << " ";
		file_out_paseadores << lista_paseadores.buscar(i).localidad << " ";
		file_out_paseadores << lista_paseadores.buscar(i).hora_entrada << " ";
		file_out_paseadores << lista_paseadores.buscar(i).hora_salida;
		if(tam_paseadores != i)
			file_out_paseadores << "\n";
	}
	file_out_paseadores.close();
}

// Escritura del archivo clientes
void write_file_clientes(lista< Cliente<Perro> > lista_clientes){
	int k=0;
	ofstream file_out_clientes("clientes.txt", ios::out|ios::trunc);
	if (!file_out_clientes.good()){
	 	cerr << "No se pudo abrir el archivo" << endl;
    	exit(1);
	}
	int tam_perros;
	int tam_clientes = lista_clientes.get_tam();
	for(int i = 1; i <= tam_clientes; i++){
		tam_perros = lista_clientes.buscar(i).num_perros;
		file_out_clientes << lista_clientes.buscar(i).nombre << " ";
		file_out_clientes << lista_clientes.buscar(i).apellido << " ";
		file_out_clientes << lista_clientes.buscar(i).id << " ";
		file_out_clientes << lista_clientes.buscar(i).sexo << " ";
		file_out_clientes << lista_clientes.buscar(i).localidad_residencia << " ";
		file_out_clientes << lista_clientes.buscar(i).num_perros << " ";
		for(int j = 1; j <= tam_perros; j++){
			file_out_clientes << lista_clientes.buscar(i).lista_perros.buscar(j).id << " ";
			file_out_clientes << lista_clientes.buscar(i).lista_perros.buscar(j).nombre << " ";
			file_out_clientes << lista_clientes.buscar(i).lista_perros.buscar(j).mes_nacimiento << " ";
			file_out_clientes << lista_clientes.buscar(i).lista_perros.buscar(j).ano_nacimiento << " ";
			file_out_clientes << lista_clientes.buscar(i).lista_perros.buscar(j).raza << " ";
			file_out_clientes << lista_clientes.buscar(i).lista_perros.buscar(j).tamano << " ";
			file_out_clientes << lista_clientes.buscar(i).lista_perros.buscar(j).concentrado;
			if(tam_perros != j)
				file_out_clientes << " ";
		}
		if(tam_clientes != i)
			file_out_clientes << endl;
	}
	file_out_clientes.close();
}

// Funcion para determinar el paseador que realizara la solicitud
void consulta_hora_localidad(lista<Paseador> lista_paseadores, lista< Cliente<Perro> > lista_clientes, int& id_paseador, int& id_cliente){
	int horainicio_buscar, horafin_buscar;
	string localidad_buscar, nombre_buscar, apellido_buscar;
	cout << "Ingrese el nombre del cliente: "	;
	cin>> nombre_buscar;
	cout << "Ingrese el apellido del cliente: "	;
	cin>> apellido_buscar;
	do{
		cout << "Ingrese la hora de inicio: "	;
		cin>> horainicio_buscar;
	}while(horainicio_buscar <= 6 || horainicio_buscar >= 19);
	do{
		cout << "Ingrese la hora de fin: "	;
		cin>> horafin_buscar;
	}while(horafin_buscar <= 6 || horafin_buscar >= 19 || horafin_buscar < horainicio_buscar);
	int tam_clientes = lista_clientes.get_tam();
	int tam_paseadores = lista_paseadores.get_tam();
	for(int i = 1; i <= tam_clientes; i++){
		if(lista_clientes.buscar(i).nombre == nombre_buscar && lista_clientes.buscar(i).apellido == apellido_buscar){
			localidad_buscar = lista_clientes.buscar(i).localidad_residencia;
			for(int j = 1; j <= tam_paseadores; j++){
				if(lista_paseadores.buscar(j).localidad== localidad_buscar && lista_paseadores.buscar(j).hora_entrada <= horainicio_buscar
					&& lista_paseadores.buscar(j).hora_salida > horafin_buscar && lista_paseadores.buscar(j).num_perros < 2){
					id_paseador = lista_paseadores.buscar(j).id;
					id_cliente = lista_clientes.buscar(i).id;	
				}
			}
		}	
	}		
	cout << endl;
}

int main(int argc, char** argv) {
	// Creacion de la lista sucursales
	Sucursal sucursal;	
	lista<Sucursal> lista_sucursales;
	// Creacion de la lista paseadores
	Paseador paseador;
	lista<Paseador> lista_paseadores;
	// Creacion de la multilista clientes
	lista< Cliente<Perro> > lista_clientes;
	Cliente<Perro> cliente;
	Perro perro;
	
	// Lectura de archivos
	read_file_sucursales(lista_sucursales, sucursal);
	read_file_paseadores(lista_paseadores, paseador);
   	read_file_clientes(lista_clientes, cliente, perro);
	
	//
	//		MENU
	//
	
	int opcion1, opcion2, opcion3;
	bool menu1 = false, menu2, menu3;
	
	while(!menu1){
		menu2 = false;
		system("cls");
		cout << " ____                      _____     _   " << endl;
		cout << "|    / ___ ___ ___ ___ ___|     |_ _| |_ " << endl;
		cout << "|  |  | . | . | . | -_|  _|  |  | | |  _|" << endl;
		cout << "|____/|___|_  |_  |___|_| |_____|___|_|  " << endl;
        cout << "          |___|___|                      " << endl << endl;
		cout << "1) Ver / Modificar Registros" << endl;
		cout << "2) Realizar Consultas" << endl;
		cout << "3) Realizar la Simulacion" << endl;
		cout << "4) Salir del Programa" << endl;
		cin >> opcion1;
		switch(opcion1){
			case 1:{
				while(!menu2){
					menu3 = false;
					system("cls");
					cout << "1) Registros de Sucursales" << endl;
					cout << "2) Registros de Paseadores" << endl;
					cout << "3) Registros de Clientes" << endl;
					cout << "4) Volver" << endl;
					cin >> opcion2;
					switch(opcion2){
						case 1:{
							while(!menu3){
								system("cls");
								cout << "1) Ver Sucursales" << endl;
								cout << "2) Agregar Sucursal" << endl;
								cout << "3) Modificar Sucursal" << endl;
								cout << "4) Eliminar Sucursal" << endl;
								cout << "5) Volver" << endl;
								cin >> opcion3;
								switch(opcion3){
									case 1:{
										// Impresion de las sucursales
										tam_sucursales = lista_sucursales.get_tam();
										for(int i = 1; i <= tam_sucursales; i++){
											cout << lista_sucursales.buscar(i).nombre_sucursal << " ";
											cout << lista_sucursales.buscar(i).nombre_gerente << " ";
											cout << lista_sucursales.buscar(i).localidad << " ";
											cout << lista_sucursales.buscar(i).calle_inicio << " ";
											cout << lista_sucursales.buscar(i).carrera_inicio << " ";
											cout << lista_sucursales.buscar(i).calle_fin << " ";
											cout << lista_sucursales.buscar(i).carrera_fin << " ";
											cout << lista_sucursales.buscar(i).num_paseadores << " ";
											cout << lista_sucursales.buscar(i).num_clientes << " ";
											cout << endl;
										}
										cout << endl;
										system("pause");
										system("cls");
										break;
									}
									case 2:{
										cout << "Agregar Sucursal" << endl;
										cout << "Nombre de la Sucursal: ";
										cin >> nom_sucursal;
										sucursal.nombre_sucursal = nom_sucursal;
										cout << "Nombre Gerente: ";
										cin >> nom_gerente;
										sucursal.nombre_gerente = nom_gerente;
										cout << "Localidad: ";
										cin >> localidad;
										sucursal.localidad = localidad;
										do{
											cout << "Calle de inicio: ";
											cin >> cll_inicio;
										}while(cll_inicio < 0);										
										sucursal.calle_inicio = cll_inicio;
										do{
											cout << "Carrera de inicio: ";
											cin >> cr_inicio;
										}while(cr_inicio < 0);										
										sucursal.carrera_inicio = cr_inicio;
										do{
											cout << "Calle de fin: ";
											cin >> cll_fin;
										}while(cll_fin < 0);
										sucursal.calle_fin = cll_fin;
										do{
											cout << "Carrera de fin: ";
											cin >> cr_fin;
										}while(cr_fin < 0);										
										sucursal.carrera_fin = cr_fin;
										sucursal.num_paseadores = 0;
										sucursal.num_clientes = 0;
										// Inserta la nueva sucursal
										lista_sucursales.insertar_inicio(sucursal);
										// Actualizacion del archivo sucursales
										write_file_sucursales(lista_sucursales);
										system("cls");
										break;
									}
									case 3:{
										cout << "Modificar Sucursal" << endl;
										cout << "Nombre Sucursal: ";
										cin >> nom_sucursal;
										modificar = false;
										tam_sucursales = lista_sucursales.get_tam();
										for(int i = 1; i <= tam_sucursales; i++){
											if(nom_sucursal == lista_sucursales.buscar(i).nombre_sucursal){
												cout << "Modificacion " << lista_sucursales.buscar(i).nombre_sucursal << endl;
												cout << "Nombre Sucursal: ";
												cin >> nom_sucursal;
												sucursal.nombre_sucursal = nom_sucursal;
												cout << "Nombre Gerente: ";
												cin >> nom_gerente;
												sucursal.nombre_gerente = nom_gerente;
												cout << "Localidad: ";
												cin >> localidad;
												sucursal.localidad = localidad;
												do{
													cout << "Calle de inicio: ";
													cin >> cll_inicio;
												}while(cll_inicio < 0);										
												sucursal.calle_inicio = cll_inicio;
												do{
													cout << "Carrera de inicio: ";
													cin >> cr_inicio;
												}while(cr_inicio < 0);										
												sucursal.carrera_inicio = cr_inicio;
												do{
													cout << "Calle de fin: ";
													cin >> cll_fin;
												}while(cll_fin < 0);
												sucursal.calle_fin = cll_fin;
												do{
													cout << "Carrera de fin: ";
													cin >> cr_fin;
												}while(cr_fin < 0);										
												sucursal.carrera_fin = cr_fin;
												sucursal.num_paseadores = lista_sucursales.buscar(i).num_paseadores;
												sucursal.num_clientes = lista_sucursales.buscar(i).num_clientes;
												pos_save = i;
												modificar = true;
											}
										}
										if(modificar){
											lista_sucursales.borrar_nodo(pos_save);
											lista_sucursales.insertar_inicio(sucursal);
										}
										// Actualizacion del archivo sucursales
										write_file_sucursales(lista_sucursales);
										system("cls");
										break;
									}
									case 4:{
										cout << "Borrar Sucursal" << endl;
										cout << "Nombre Sucursal: ";
										cin >> nom_sucursal;
										modificar = false;
										tam_sucursales = lista_sucursales.get_tam();
										for(int i = 1; i <= tam_sucursales; i++){
											if(nom_sucursal == lista_sucursales.buscar(i).nombre_sucursal){
												if((lista_sucursales.buscar(i).num_paseadores == 0) && (lista_sucursales.buscar(i).num_clientes == 0)){
													pos_save = i;
													modificar = true;
												}else{
													cout << "La sucursal tiene clientes y/o paseadores \nNo se puede eliminar" << endl;
												}
											}
										}
										// Eliminacion de la sucursal
										if(modificar){
											lista_sucursales.borrar_nodo(pos_save);
										}
										// Actualizacion del archivo sucursales
										write_file_sucursales(lista_sucursales);
										system("cls");
										break;
									}
									default:{
										menu3 = true;
									}
								}
							}
							break;
						}
						case 2:{
							while(!menu3){
								system("cls");
								cout << "1) Ver Paseadores" << endl;
								cout << "2) Agregar Paseador" << endl;
								cout << "3) Modificar Paseador" << endl;
								cout << "4) Eliminar Paseador" << endl;
								cout << "5) Volver" << endl;
								cin >> opcion3;
								
								switch(opcion3){
									case 1:{
										// Impresion de los datos basicos de cada paseador
										tam_paseadores = lista_paseadores.get_tam();
										for(int i = 1; i <= tam_paseadores; i++){
											cout << lista_paseadores.buscar(i).sucursal << " ";
											cout << lista_paseadores.buscar(i).nombre << " ";
											//cout << lista_paseadores.buscar(i).apellido << " ";
											cout << lista_paseadores.buscar(i).tipo_id << " ";
											cout << lista_paseadores.buscar(i).id << " ";
											cout << lista_paseadores.buscar(i).sexo << " ";
											//cout << lista_paseadores.buscar(i).tel_fijo << " ";
											//cout << lista_paseadores.buscar(i).tel_celular << " ";
											//cout << lista_paseadores.buscar(i).e_mail << " ";
											//cout << lista_paseadores.buscar(i).dia_nacimiento << " ";
											cout << lista_paseadores.buscar(i).mes_nacimiento << " ";
											cout << lista_paseadores.buscar(i).ano_nacimiento << " ";
											//cout << lista_paseadores.buscar(i).ciudad_nacimiento << " ";
											//cout << lista_paseadores.buscar(i).pais_nacimiento << " ";
											//cout << lista_paseadores.buscar(i).direccion << " ";
											cout << lista_paseadores.buscar(i).localidad << " ";
											cout << lista_paseadores.buscar(i).hora_entrada << " ";
											cout << lista_paseadores.buscar(i).hora_salida << " ";
											cout << lista_paseadores.buscar(i).num_perros << " ";
											cout << endl;
										}
										cout << endl;
										system("pause");
										system("cls");
										break;
									}
									case 2:{
										cout << "Agregar Paseador" << endl;
										cout << "Sucursal: ";
										cin >> nom_sucursal;
										modificar = false;
										tam_sucursales = lista_sucursales.get_tam();
										for(int i = 1; i <= tam_sucursales; i++){
											if(lista_sucursales.buscar(i).nombre_sucursal == nom_sucursal){
												paseador.sucursal = nom_sucursal;
												cout << "Nombre: ";
												cin >> nombre;
												paseador.nombre = nombre;
												cout << "Apellido: ";
												cin >> apellido;
												paseador.apellido = apellido;
												cout << "Tipo ID: ";
												cin >> tipo_id;
												paseador.tipo_id = tipo_id;
												cout << "ID: ";
												cin >> id;
												paseador.id = id;
												cout << "Sexo: ";
												cin >> sexo;
												paseador.sexo = sexo;
												cout << "Telefono fijo: ";
												cin >> tel_fijo;
												paseador.tel_fijo = tel_fijo;
												cout << "Telefono celular: ";
												cin >> tel_celular;
												paseador.tel_celular = tel_celular;
												cout << "E-Mail: ";
												cin >> e_mail;
												paseador.e_mail = e_mail;
												do{
													cout << "Año de nacimiento: ";
													cin >> ano_nacimiento;
												}while(ano_nacimiento >= 2000);
												paseador.ano_nacimiento = ano_nacimiento;
												do{
													cout << "Mes de nacimiento: ";
													cin >> mes_nacimiento;
												}while(mes_nacimiento <= 0 || mes_nacimiento >=13);
												paseador.mes_nacimiento = mes_nacimiento;
												if(mes_nacimiento == 1 || mes_nacimiento == 3 || mes_nacimiento == 5 || mes_nacimiento == 7 || mes_nacimiento == 8 || mes_nacimiento == 10 || mes_nacimiento == 12){
													do{
														cout << "Dia de nacimiento: ";
														cin >> dia_nacimiento;
													}while(dia_nacimiento <= 0 || dia_nacimiento >= 32);
													paseador.dia_nacimiento = dia_nacimiento;
												}else if(mes_nacimiento == 4 || mes_nacimiento == 6 || mes_nacimiento == 9 || mes_nacimiento == 11){
													do{
														cout << "Dia de nacimiento: ";
														cin >> dia_nacimiento;
													}while(dia_nacimiento <= 0 || dia_nacimiento >= 31);
													paseador.dia_nacimiento = dia_nacimiento;
												}else if(mes_nacimiento == 2){
													// No tiene en cuenta años biciestos
													do{
														cout << "Dia de nacimiento: ";
														cin >> dia_nacimiento;
													}while(dia_nacimiento <= 0 || dia_nacimiento >= 29);
													paseador.dia_nacimiento = dia_nacimiento;
												}
												cout << "Ciudad de nacimiento: ";
												cin >> ciudad_nacimiento;
												paseador.ciudad_nacimiento = ciudad_nacimiento;
												cout << "Pais de nacimiento: ";
												cin >> pais_nacimiento;
												paseador.pais_nacimiento = pais_nacimiento;
												cout << "Direccion de residencia: ";
												cin >> dir_paseador;
												paseador.direccion = dir_paseador;
												cout << "Localidad de residencia: ";
												cin >> localidad_paseador;
												paseador.localidad = localidad_paseador;
												cout << "Hora de entrada (24H): ";
												cin >> h_entrada;
												paseador.hora_entrada = h_entrada;
												cout << "Hora de salida (24H): ";
												cin >> h_salida;
												paseador.hora_salida = h_salida;
												
												sucursal = lista_sucursales.buscar(i);
												sucursal.num_paseadores++;
												pos_save = i;
												modificar = true;
												// Insercion de un nuevo paseador
												lista_paseadores.insertar_inicio(paseador);
											}
										}
										// Actualizacion de la sucursal
										if(modificar){
											lista_sucursales.borrar_nodo(pos_save);
											lista_sucursales.insertar_inicio(sucursal);
										}
										// Actualizacion del archivo paseadores
										write_file_paseadores(lista_paseadores);
										// Actualizacion del archivo sucursales
										write_file_sucursales(lista_sucursales);
										system("cls");
										break;
									}
									case 3:{
										// Actualizacion del archivo paseadores
										write_file_paseadores(lista_paseadores);
										system("cls");
										break;
									}
									case 4:{
										int pos1=0;
										cout << "Eliminar Paseador" << endl;
										cout << "ID: ";
										cin >> id;
										modificar = false;
										tam_paseadores = lista_paseadores.get_tam();
										for(int i = 1; i <= tam_paseadores; i++){
											if(lista_paseadores.buscar(i).id == id){
												pos_save = i;
												modificar = true;
												tam_sucursales = lista_sucursales.get_tam();
												for(int j = 1; j <= tam_sucursales; j++){
													if(lista_paseadores.buscar(i).sucursal == lista_sucursales.buscar(j).nombre_sucursal){
														sucursal = lista_sucursales.buscar(j);
														sucursal.num_paseadores--;
														pos1=j;
													}
												}
											}
										}
										// Eliminacion del paseador y actualizacion de la sucursal
										if(modificar){
											lista_paseadores.borrar_nodo(pos_save);
											lista_sucursales.borrar_nodo(pos1);
											lista_sucursales.insertar_inicio(sucursal);
										}
										// Actualizacion del archivo paseadores
										write_file_paseadores(lista_paseadores);
										// Actualizacion del archivo sucursales
										write_file_sucursales(lista_sucursales);
										system("cls");
										break;
									}
									default:{
										menu3 = true;
									}
								}
							}
							break;
						}
						case 3:{
							while(!menu3){
								// Impresion de los clientes junto con sus perros
								system("cls");
								cout << "1) Ver Clientes" << endl;
								cout << "2) Agregar Cliente" << endl;
								cout << "3) Modificar Cliente" << endl;
								cout << "4) Eliminar Cliente" << endl;
								cout << "5) Volver" << endl;
								cin >> opcion3;
								switch(opcion3){
									case 1:{
										tam_clientes = lista_clientes.get_tam();
										for(int i = 1; i <= tam_clientes; i++){
											tam_perros = lista_clientes.buscar(i).num_perros;
											cout << lista_clientes.buscar(i).nombre << " ";
											cout << lista_clientes.buscar(i).apellido << " ";
											cout << lista_clientes.buscar(i).id << " ";
											cout << lista_clientes.buscar(i).sexo << " ";
											cout << lista_clientes.buscar(i).localidad_residencia << " ";
											cout << endl;
											for(int j = 1; j <= tam_perros; j++){
												cout << "  " << lista_clientes.buscar(i).lista_perros.buscar(j).id << " ";
												cout << lista_clientes.buscar(i).lista_perros.buscar(j).nombre << " ";
												cout << lista_clientes.buscar(i).lista_perros.buscar(j).mes_nacimiento << " ";
												cout << lista_clientes.buscar(i).lista_perros.buscar(j).ano_nacimiento << " ";
												cout << lista_clientes.buscar(i).lista_perros.buscar(j).raza << " ";
												cout << lista_clientes.buscar(i).lista_perros.buscar(j).tamano << " ";
												//cout << lista_clientes.buscar(i).lista_perros.buscar(j).concentrado << " ";
												cout << endl;
											}
											cout << endl;
										}
										cout << endl;
										system("pause");
										system("cls");
										break;
									}
									case 2:{
										// Actualizacion del archivo clientes
										write_file_clientes(lista_clientes);
										system("cls");
										break;
									}
									case 3:{
										// Actualizacion del archivo clientes
										write_file_clientes(lista_clientes);
										system("cls");
										break;
									}
									case 4:{
										// Actualizacion del archivo clientes
										write_file_clientes(lista_clientes);
										system("cls");
										break;
									}
									default:{
										menu3 = true;
									}
								}
							}
							break;
						}
						default:{
							menu2 = true;
						}
					}
					
				}
				break;
			}
			case 2:{
				while(!menu2){
					menu3 = false;
					system("cls");
					cout << "1) Consultar una sucursal por un area definida por calle y carrera" << endl;
					cout << "2) Consultar paseadores disponibles por hora y localidad" << endl;
					cout << "3) Consultar paseadores disponibles por cliente y hora" << endl;
					cout << "4) Consultar clientes por localidad y raza de perro" << endl;
					cout << "5) Consultar perros por localidad y tamano" << endl;
					cout << "6) Atras" << endl;
					cin >> opcion2;
					switch(opcion2){
						case 1:{
							int calle_buscar, cra_buscar;
							cout << "Ingrese el n?mero de la calle: "	;
							cin>> calle_buscar;
							cout << "Ingrese el n?mero de la carrera: ";
							cin>> cra_buscar;
							
							tam_sucursales = lista_sucursales.get_tam();
							for(int i = 1; i <= tam_sucursales; i++){
								if(lista_sucursales.buscar(i).calle_fin > calle_buscar && lista_sucursales.buscar(i).calle_inicio < calle_buscar
									&& lista_sucursales.buscar(i).carrera_fin > cra_buscar && lista_sucursales.buscar(i).carrera_inicio < cra_buscar){
									cout <<"La sucursal que puede hacerse cargo es: " <<lista_sucursales.buscar(i).nombre_sucursal << " " << endl;
								}
							}
							cout << endl;
							system("pause");
							system("cls");
							break;
						}
						case 2:{
							int horainicio_buscar, horafin_buscar;
							string localidad_buscar;
							cout << "Ingrese la hora de inicio: "	;
							cin>> horainicio_buscar;
							cout << "Ingrese la hora de fin: "	;
							cin>> horafin_buscar;
							cout << "Ingrese la localidad: ";
							cin>> localidad_buscar;
							
							tam_paseadores = lista_paseadores.get_tam();
							for(int i = 1; i <= tam_paseadores; i++){
								if(lista_paseadores.buscar(i).localidad == localidad_buscar && lista_paseadores.buscar(i).hora_entrada <= horainicio_buscar
									&& lista_paseadores.buscar(i).hora_salida >= horafin_buscar){
									cout<<"El paseador encargado es: ";
									cout << lista_paseadores.buscar(i).nombre << " ";
									cout << lista_paseadores.buscar(i).apellido << " ";
									cout << endl;
								}
							}
							cout << endl;
							system("pause");
							system("cls");
							break;
						}
						case 3:{
							int horainicio_buscar, horafin_buscar;
							string localidad_buscar, nombre_buscar, apellido_buscar;
							cout << "Ingrese nombre de cliente: "	;
							cin>> nombre_buscar;
							cout << "Ingrese apellido de cliente: "	;
							cin>> apellido_buscar;
							cout << "Ingrese la hora de inicio: "	;
							cin>> horainicio_buscar;
							cout << "Ingrese la hora de fin: "	;
							cin>> horafin_buscar;
								
							tam_clientes = lista_clientes.get_tam();
							tam_paseadores = lista_paseadores.get_tam();
							for(int i = 1; i <= tam_clientes; i++){
								if(lista_clientes.buscar(i).nombre == nombre_buscar && lista_clientes.buscar(i).apellido == apellido_buscar){
									localidad_buscar = lista_clientes.buscar(i).localidad_residencia;
									for(int j = 1; j <= tam_paseadores; j++){
										if(lista_paseadores.buscar(j).localidad== localidad_buscar && lista_paseadores.buscar(j).hora_entrada <= horainicio_buscar
											&& lista_paseadores.buscar(j).hora_salida > horafin_buscar && lista_paseadores.buscar(j).num_perros < 2){
											cout<<"El paseador encargado es: ";
											cout << lista_paseadores.buscar(j).nombre << " ";
											cout << lista_paseadores.buscar(j).apellido << " ";
											cout << endl;	
										}
									}
								}	
							}		
							cout << endl;
							system("pause");
							system("cls");
							break;
						}
						case 4:{
							string localidad_buscar, raza_buscar;
							cout << "Ingrese la localidad: ";
							cin>> localidad_buscar;
							cout << "Ingrese la raza: ";
							cin>> raza_buscar;
							tam_clientes = lista_clientes.get_tam();
							for(int i = 1; i <= tam_clientes; i++){
								tam_perros = lista_clientes.buscar(i).num_perros;
								if(lista_clientes.buscar(i).localidad_residencia==localidad_buscar){
									for(int j = 1; j <= tam_perros; j++) {
										if(lista_clientes.buscar(i).lista_perros.buscar(j).raza==raza_buscar){
											cout<<"Los clientes son: ";
											cout<<lista_clientes.buscar(i).nombre<< " ";
											cout<<lista_clientes.buscar(i).apellido<< " ";
											cout << endl;
										}
									}
								}
							}
							cout << endl;
							system("pause");
							system("cls");
							break;
						}
						case 5:{
							string localidad_buscar, tamano_buscar;
							cout << "Ingrese la localidad: ";
							cin>> localidad_buscar;
							cout << "Ingrese el tamano del perro: ";
							cin>> tamano_buscar;
							tam_clientes = lista_clientes.get_tam();
							for(int i = 1; i <= tam_clientes; i++){
								tam_perros = lista_clientes.buscar(i).num_perros;
								if(lista_clientes.buscar(i).localidad_residencia==localidad_buscar){
									for(int j = 1; j <= tam_perros; j++) {
										if(lista_clientes.buscar(i).lista_perros.buscar(j).tamano==tamano_buscar){
											cout << "Los perros son: ";
											cout << lista_clientes.buscar(i).lista_perros.buscar(j).nombre << " ";
											cout << endl;
										}
									}
								}
							}
							cout << endl;
							system("pause");
							system("cls");
							break;
						}
						default:{
							menu2 = true;
							break;
						}
					}
				}
				break;
			}
			case 3:{
				while(!menu2){
					int id_paseador, id_cliente, id_perro, pos1, pos2;
					modificar = false;
					menu3 = false;
					system("cls");
					cout << "1) Solicitar paseador." << endl;
					cout << "2) Terminar simulacion." << endl;
					cout << "3) Atras" << endl;
					cin >> opcion2;
					switch(opcion2){
						case 1:{
							consulta_hora_localidad(lista_paseadores, lista_clientes, id_paseador, id_cliente);
							//cout << id_paseador << endl; // ID del paseador que llevara acabo la solicitud
							//cout << id_cliente << endl;  // ID del cliente que requiere la solicitud
							tam_paseadores = lista_paseadores.get_tam();
							for(int i = 1; i <= tam_paseadores; i++){
								tam_clientes = lista_clientes.get_tam();
								if(lista_paseadores.buscar(i).id == id_paseador){
									paseador = lista_paseadores.buscar(i);
									pos_save = i;
									for(int j = 1; j <= tam_clientes; j++){
										tam_perros = lista_clientes.buscar(j).num_perros;
										if(lista_clientes.buscar(j).id == id_cliente){
											cliente = lista_clientes.buscar(j);
											pos1=j;
											for(int k = 1; k <= tam_perros; k++){
												pos2=k;
												perro = lista_clientes.buscar(j).lista_perros.buscar(k);
												modificar = true;
												break;
											}
										}
									}
								}
							}
							if(modificar){
								lista_paseadores.borrar_nodo(pos_save);
								lista_clientes.borrar_nodo(pos1);
								if(paseador.num_perros <= 1 && cliente.num_perros >= 1){
									paseador.num_perros++;
									paseador.perros_paseador.insertar_inicio(perro);
									cout << "El perro " << cliente.lista_perros.buscar(pos2).nombre << " ha sido añadido al paseador " << paseador.nombre << endl;
									cliente.num_perros--;
									cliente.lista_perros.borrar_nodo(pos2);
								}else if(paseador.num_perros >= 2){
									cout << "El paseador no esta disponible" << endl;
								}
								lista_clientes.insertar_inicio(cliente);
								lista_paseadores.insertar_inicio(paseador);
							}else if(lista_clientes.buscar(pos1).num_perros < 1){
								cout << "El cliente no posee mas perros" << endl;
							}
							
							system("pause");
							system("cls");
							break;
						}
						case 2:{
							
							break;
						}
						default:{
							menu2 = true;
							break;
						}
					}
				}
				break;
			}
			default:{
				menu1 = true;
			}
		}
	}
	return 0;
}
