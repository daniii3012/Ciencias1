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
#include <string>
#include "lista.h"
#include "sucursal.h"
#include "paseador.h"
#include "cliente.h"

using namespace std;

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

int main(int argc, char** argv) {
	
	//
	//				LECTURA DE ARCHIVOS	
	//	
	
	int pos_save = 0;
	bool modificar = false;
	long long tel_celular, id;
	int tam_sucursales, tam_paseadores, tam_clientes, tam_perros, num_paseadores, num_clientes, tel_fijo,
		dia_nacimiento, mes_nacimiento, ano_nacimiento, num_perros, h_entrada, h_salida;
	string nom_sucursal, nom_gerente, localidad;
	int cll_inicio, cr_inicio, cll_fin, cr_fin;
	
	Sucursal sucursal;	
	lista<Sucursal> lista_sucursales;
	
	string nombre, apellido, tipo_id, sexo, e_mail, ciudad_nacimiento, pais_nacimiento, dir_paseador, localidad_paseador,
		raza, tamano, concentrado;
	
	Paseador paseador;
	lista<Paseador> lista_paseadores;
	
	lista< Cliente<Perro> > lista_clientes;
	Perro perro;
	Cliente<Perro> cliente;
	
	
	// Lectura de sucursales y creacion de la lista sucursales  	
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
	
	
	// Lectura de los paseadores y creacion de la lista de paseadores
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
   	
   	
   	// Lectura de clientes y creacion de la lista de clientes
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
	
	//
	//			MENU
	//
	
	int opcion1, opcion2, opcion3;
	bool menu1 = false, menu2, menu3;
	
	while(!menu1){
		menu2 = false;
		
		cout << "1) Administrar" << endl;
		cout << "2) Consulta 1" << endl;
		cout << "3) Consulta 2" << endl;
		cout << "4) Consulta 3" << endl;
		cout << "5) Consulta 4" << endl;
		cout << "6) Salir" << endl;
		cin >> opcion1;
		
		switch(opcion1){
			case 1:{
				while(!menu2){
					menu3 = false;
					
					cout << "1) Sucursales" << endl;
					cout << "2) Paseadores" << endl;
					cout << "3) Clientes" << endl;
					cout << "4) Atras" << endl;
					cin >> opcion2;
					
					switch(opcion2){
						case 1:{
							while(!menu3){
								cout << "1) Ver Sucursales" << endl;
								cout << "2) Agregar Sucursal" << endl;
								cout << "3) Modificar Sucursal" << endl;
								cout << "4) Eliminar Sucursal" << endl;
								cout << "5) Atras" << endl;
								cin >> opcion3;
								
								switch(opcion3){
									case 1:{
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
										break;
									}
									case 2:{
										cout << "Agregar Sucursal" << endl;
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
										sucursal.num_paseadores = 0;
										sucursal.num_clientes = 0;
										lista_sucursales.insertar_inicio(sucursal);
										
										write_file_sucursales(lista_sucursales);
										
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
										
										write_file_sucursales(lista_sucursales);
										
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
										if(modificar){
											lista_sucursales.borrar_nodo(pos_save);
										}
										
										write_file_sucursales(lista_sucursales);
										
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
								cout << "1) Ver Paseadores" << endl;
								cout << "2) Agregar Paseador" << endl;
								cout << "3) Modificar Paseador" << endl;
								cout << "4) Eliminar Paseador" << endl;
								cout << "5) Atras" << endl;
								cin >> opcion3;
								
								switch(opcion3){
									case 1:{
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
												lista_paseadores.insertar_inicio(paseador);
											}
										}
										if(modificar){
											lista_sucursales.borrar_nodo(pos_save);
											lista_sucursales.insertar_inicio(sucursal);
										}
										
										write_file_paseadores(lista_paseadores);
										write_file_sucursales(lista_sucursales);
										
										break;
									}
									case 3:{
										write_file_paseadores(lista_paseadores);
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
										if(modificar){
											lista_paseadores.borrar_nodo(pos_save);
											lista_sucursales.borrar_nodo(pos1);
											lista_sucursales.insertar_inicio(sucursal);
										}
										
										write_file_paseadores(lista_paseadores);
										write_file_sucursales(lista_sucursales);
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
								cout << "1) Ver Clientes" << endl;
								cout << "2) Agregar Cliente" << endl;
								cout << "3) Modificar Cliente" << endl;
								cout << "4) Eliminar Cliente" << endl;
								cout << "5) Atras" << endl;
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
												cout << lista_clientes.buscar(i).lista_perros.buscar(j).id << " ";
												cout << lista_clientes.buscar(i).lista_perros.buscar(j).nombre << " ";
												cout << lista_clientes.buscar(i).lista_perros.buscar(j).mes_nacimiento << " ";
												cout << lista_clientes.buscar(i).lista_perros.buscar(j).ano_nacimiento << " ";
												cout << lista_clientes.buscar(i).lista_perros.buscar(j).raza << " ";
												cout << lista_clientes.buscar(i).lista_perros.buscar(j).tamano << " ";
												cout << lista_clientes.buscar(i).lista_perros.buscar(j).concentrado << " ";
												cout << endl;
											}
										}
										cout << endl;
										break;
									}
									case 2:{
										write_file_clientes(lista_clientes);
										break;
									}
									case 3:{
										write_file_clientes(lista_clientes);
										break;
									}
									case 4:{
										write_file_clientes(lista_clientes);
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
				int calle_buscar, cra_buscar;
				cout << "Ingrese el n?mero de la calle: "	;
				cin>> calle_buscar;
				cout << "Ingrese el n?mero de la carrera: ";
				cin>> cra_buscar;
				
				tam_sucursales = lista_sucursales.get_tam();
				for(int i = 1; i <= tam_sucursales; i++){
					if(lista_sucursales.buscar(i).calle_fin > calle_buscar){
						//cout<< "Calle es menor que calle fin";
						if(lista_sucursales.buscar(i).calle_inicio < calle_buscar){
						//	cout<<"Calle es mayor que calle inicial";
							if(lista_sucursales.buscar(i).carrera_fin > cra_buscar){
						//		cout<<"Carrera es menor que cra fin";
								if(lista_sucursales.buscar(i).carrera_inicio < cra_buscar ){
						//				cout<<"Carrera es menor que cra fin";
										cout <<"La sucursal que puede hacerse cargo es: " <<lista_sucursales.buscar(i).nombre_sucursal << " ";				
								}
							}
						}
					}
				}
				cout << endl;
				break;
			}
			case 3:{
				int horainicio_buscar, horafin_buscar;
				string localidad_buscar;
				cout << "Ingrese la hora de inicio: "	;
				cin>> horainicio_buscar;
				cout << "Ingrese la hora de fin : "	;
				cin>> horafin_buscar;
				cout << "Ingrese la localidad: ";
				cin>> localidad_buscar;
				
				tam_paseadores = lista_paseadores.get_tam();
				for(int i = 1; i <= tam_paseadores; i++){
					if(lista_paseadores.buscar(i).localidad== localidad_buscar){
			//			cout<<"Localidad esta";
						if(lista_paseadores.buscar(i).hora_entrada <= horainicio_buscar){
			//				cout<<"Horario del paseador es menor o igual a la indicada";
							if(lista_paseadores.buscar(i).hora_salida >= horafin_buscar){
			//					cout<<"Horario final del paseador es mayor o igual a la indicada";
								cout<<"El paseador encargado es: ";
								cout << lista_paseadores.buscar(i).nombre << " ";
								cout << lista_paseadores.buscar(i).apellido << " ";
							}
						}
					}
				}
				cout << endl;
				break;
			}
			case 4:{
				int horainicio_buscar, horafin_buscar;
				string localidad_buscar, nombre_buscar, apellido_buscar;
				cout << "Ingrese nombre de cliente: "	;
				cin>> nombre_buscar;
				cout << "Ingrese apellido de cliente : "	;
				cin>> apellido_buscar;
				cout << "Ingrese la hora de inicio : "	;
				cin>> horainicio_buscar;
				cout << "Ingrese la hora de fin : "	;
				cin>> horafin_buscar;
					
				tam_clientes = lista_clientes.get_tam();
				tam_paseadores = lista_paseadores.get_tam();
				for(int i = 1; i <= tam_clientes; i++){
					if(lista_clientes.buscar(i).nombre == nombre_buscar ){
//						cout <<"Nombre está";
						if(lista_clientes.buscar(i).apellido == apellido_buscar){
//							cout<<"Apellido está";
							localidad_buscar = lista_clientes.buscar(i).localidad_residencia;
							for(int j = 1; j <= tam_paseadores; j++){
								if(lista_paseadores.buscar(j).localidad== localidad_buscar){
//									cout<<"Localidad esta";
									if(lista_paseadores.buscar(j).hora_entrada <= horainicio_buscar){
//										cout<<"Horario del paseador es menor o igual a la indicada";
										if(lista_paseadores.buscar(j).hora_salida >= horafin_buscar){
//											cout<<"Horario final del paseador es mayor o igual a la indicada";
											cout<<"El paseador encargado es: ";
											cout << lista_paseadores.buscar(j).nombre << " ";
											cout << lista_paseadores.buscar(j).apellido << " ";
											cout << endl;
										}
									}	
								}
							}
						}
					}	
				}		
				cout << endl;
				break;
			}
			case 5:{
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
				break;
			}
			default:{
				menu1 = true;
			}
		}
	}
	
	return 0;
}

