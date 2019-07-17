/*
	Angie Gabriela Antolinez - 20151020061
	Daniel Alejandro Montiel - 20171020049
*/
#ifndef PASEADOR_H
#define PASEADOR_H
#include "lista.h"
#include "cliente.h"

struct Paseador{
	string sucursal;
	string nombre;
	string apellido;
	string tipo_id;
	long long id;
	string genero;
	int tel_fijo;
	long long tel_celular;
	string e_mail;
	
	int dia_nacimiento;
	int mes_nacimiento;
	int ano_nacimiento;
	
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
