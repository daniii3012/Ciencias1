#include <iostream>
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
	return 0;
}
