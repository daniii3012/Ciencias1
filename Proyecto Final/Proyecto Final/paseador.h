/*
	Angie Gabriela Antolinez - 20151020061
	Daniel Alejandro Montiel - 20171020049
*/
#ifndef PASEADOR_H
#define PASEADOR_H
#include "lista.h"
#include "cliente.h"
// Creaci�n de la estructura Paseador
struct Paseador{
	// Creaci�n de atributos string de la estructura 
	string sucursal;
	string nombre;
	string apellido;
	string tipo_id;
	long long id;
	string genero;
	int tel_fijo;
	long long tel_celular;
	string e_mail;
	// Creaci�n de atributos int- n�mericos de la estructura 
	int dia_nacimiento;
	int mes_nacimiento;
	int ano_nacimiento;
	// Creaci�n de atributos string e int- n�mericos de la estructura 
	string ciudad_nacimiento;
	string pais_nacimiento;
	string direccion;
	string localidad;
	
	int hora_entrada;
	int hora_salida;
	
	int num_perros;
	
	lista<Perro> perros_paseador;
};

#endif
