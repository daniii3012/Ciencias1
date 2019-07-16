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

int main(int argc, char** argv) {
	
	long long tel_celular, id;
	int tam_sucursales, tam_paseadores, tam_clientes, tam_perros, num_paseadores, num_clientes, tel_fijo,
		dia_nacimiento, mes_nacimiento, ano_nacimiento, num_perros, h_entrada, h_salida;
	string nom_sucursal, nom_gerente, localidad;
	int cll_inicio, cr_inicio, cll_fin, cr_fin;
	
	Sucursal sucursal;	
	lista<Sucursal> lista_sucursales;
	
	string nombre, apellido, tipo_id, sexo, e_mail, ciudad_nacimiento, pais_nacimiento, dir_paseador, barrio_paseador,
		raza, tamano, concentrado;
	
	Paseador paseador;
	lista<Paseador> lista_paseadores;
	
	lista< Cliente<Perro> > lista_clientes;
	Perro perro;
	Cliente<Perro> cliente;
	
	ifstream file_in_sucursales("sucursales.txt", ios::in);
 	//ofstream file_out_sucursales("sucursales.txt", ios::out|ios::trunc);

 	if (!file_in_sucursales.good()){
	 	cerr << "No se pudo abrir el archivo" << endl;
    	exit(1);
	}
	/*
 	if (!file_out_sucursales.good()){
	 	cerr << "No se pudo abrir el archivo" << endl;
    	exit(1);
	}
	*/
	// Lectura de sucursales y creacion de la lista sucursales   
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
	
		
	ifstream file_in_paseadores("paseadores.txt", ios::in);
 	//ofstream file_out_paseadores("paseadores.txt", ios::out|ios::trunc);

 	if (!file_in_paseadores.good()){
	 	cerr << "No se pudo abrir el archivo" << endl;
    	exit(1);
	}
	
	// Lectura de los paseadores y creacion de la lista de paseadores
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
    	file_in_paseadores >> barrio_paseador;
    	paseador.barrio = barrio_paseador;
    	file_in_paseadores >> h_entrada;
    	paseador.hora_entrada = h_entrada;
    	file_in_paseadores >> h_salida;
    	paseador.hora_salida = h_salida;
    	
    	lista_paseadores.insertar_inicio(paseador);
   	}
   	file_in_paseadores.close();
   	
   	tam_paseadores = lista_paseadores.get_tam();
	for(int i = 1; i <= tam_paseadores; i++){
		cout << lista_paseadores.buscar(i).sucursal << " ";
		cout << lista_paseadores.buscar(i).nombre << " ";
		cout << lista_paseadores.buscar(i).apellido << " ";
		cout << lista_paseadores.buscar(i).tipo_id << " ";
		cout << lista_paseadores.buscar(i).id << " ";
		cout << lista_paseadores.buscar(i).sexo << " ";
		cout << lista_paseadores.buscar(i).tel_fijo << " ";
		cout << lista_paseadores.buscar(i).tel_celular << " ";
		cout << lista_paseadores.buscar(i).e_mail << " ";
		cout << lista_paseadores.buscar(i).dia_nacimiento << " ";
		cout << lista_paseadores.buscar(i).mes_nacimiento << " ";
		cout << lista_paseadores.buscar(i).ano_nacimiento << " ";
		cout << lista_paseadores.buscar(i).ciudad_nacimiento << " ";
		cout << lista_paseadores.buscar(i).pais_nacimiento << " ";
		cout << lista_paseadores.buscar(i).direccion << " ";
		cout << lista_paseadores.buscar(i).barrio << " ";
		cout << endl;
	}
	cout << endl;
	
	
	ifstream file_in_clientes("clientes.txt", ios::in);
 	//ofstream file_out_clientes("clientes.txt", ios::out|ios::trunc);

 	if (!file_in_clientes.good()){
	 	cerr << "No se pudo abrir el archivo" << endl;
    	exit(1);
	}	
	
	// Lectura de clientes y creacion de la lista de clientes   
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
	file_in_sucursales.close();
	
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
			cout << "	" << lista_clientes.buscar(i).lista_perros.buscar(j).nombre << " ";
			cout << lista_clientes.buscar(i).lista_perros.buscar(j).mes_nacimiento << " ";
			cout << lista_clientes.buscar(i).lista_perros.buscar(j).ano_nacimiento << " ";
			cout << lista_clientes.buscar(i).lista_perros.buscar(j).raza << " ";
			cout << lista_clientes.buscar(i).lista_perros.buscar(j).tamano << " ";
			cout << lista_clientes.buscar(i).lista_perros.buscar(j).concentrado << " ";
			cout << endl;
		}
	}
	cout << endl;
	
	int calle_buscar, cra_buscar;
	cout << "Ingrese el número de la calle: "	;
	cin>> calle_buscar;
	cout << "Ingrese el número de la carrera: ";
	cin>> cra_buscar;
	for(int i = 1; i <= tam_sucursales; i++){
		if((lista_sucursales.buscar(i).calle_fin) > calle_buscar){
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
	
	return 0;
}
