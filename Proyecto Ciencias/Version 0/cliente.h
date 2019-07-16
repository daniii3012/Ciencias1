/*
	Angie Gabriela Antolinez - 20151020061
	Daniel Alejandro Montiel - 20171020049
*/
#ifndef CLIENTE_H
#define CLIENTE_H
#include "lista.h"

struct Perro{
	int id;
	
	string nombre;
	
	//int dia_nacimiento;
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
	long long id;
	string sexo;
	string localidad_residencia;
	int num_perros;
	
	lista<T> lista_perros;
};

#endif
