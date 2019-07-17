/*
	Angie Gabriela Antolinez - 20151020061
	Daniel Alejandro Montiel - 20171020049
*/
#ifndef SUCURSAL_H
#define SUCURSAL_H
// Creación de la estructura sucursales
struct Sucursal{
	// Creación de atributos string de la estructura 
	string nombre_sucursal;
	string nombre_gerente;
	string localidad;
	// Creación de atributos int- númericos de la estructura 
	int calle_inicio;
	int carrera_inicio;
	int calle_fin;
	int carrera_fin;
	
	int num_paseadores;
	int num_clientes;
};

#endif
