/*
	Angie Gabriela Antolinez - 20151020061
	Daniel Alejandro Montiel - 20171020049
*/
#ifndef CLIENTE_H
#define CLIENTE_H
#include "lista.h"
// Creación de la estructura Perro
struct Perro{
	int id;
	
	string nombre;
	
	//int dia_nacimiento;
	int mes_nacimiento;
	int ano_nacimiento;
	// Creación de atributos string de la estructura 
	string raza;
	string tamano;
	string concentrado;
};

template <class T>
// Creación de la estructura Cliente
struct Cliente{
	// Creación de atributos string e int- númericos de la estructura 
	string nombre;
	string apellido;
	long long id;
	string genero;
	string localidad_residencia;
	int num_perros;
	
	lista<T> lista_perros;
};

#endif
