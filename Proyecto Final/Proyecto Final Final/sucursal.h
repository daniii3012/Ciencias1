/*
	Angie Gabriela Antolinez - 20151020061
	Daniel Alejandro Montiel - 20171020049
*/
#ifndef SUCURSAL_H
#define SUCURSAL_H
// Creaci�n de la estructura sucursales
struct Sucursal{
	// Creaci�n de atributos string de la estructura 
	string nombre_sucursal;
	string nombre_gerente;
	string localidad;
	// Creaci�n de atributos int- n�mericos de la estructura 
	int calle_inicio;
	int carrera_inicio;
	int calle_fin;
	int carrera_fin;
	
	int num_paseadores;
	int num_clientes;
};

#endif
