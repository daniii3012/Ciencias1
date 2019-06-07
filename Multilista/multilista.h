/*
	Daniel Alejandro Montiel - 20171020049
	Angie Gabriela Antolinez - 20151020061
*/

#ifndef MULTILISTA_H
#define MULTILISTA_H

#include <iostream>
using namespace std;

struct estudiante{
	string nombre, carrera, hobby;
	int edad = 0;
	
	int sig_nombre = 0, sig_carrera = 0, sig_hobby = 0, sig_edad = 0;
};

struct cabecera{
	string dato;
	int pos = 0;
};

class multilista{
	estudiante est[11];
	cabecera cab[10];
	
	public: multilista(){
		
	}
};

#endif
