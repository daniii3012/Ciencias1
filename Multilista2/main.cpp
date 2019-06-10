/*
	Daniel Alejandro Montiel - 20171020049
	Angie Gabriela Antolinez - 20151020061
*/

#include <iostream>
#include "multilista.h"

using namespace std;

int main(int argc, char** argv) {
	string nombre, carrera, hobby;
	int edad;
	int i, j, l,k, lo;
	cout<<"Ingrese el número de estudiantes que desea ingresar: ";
	cin>>k;
	lo=k+1;
	multi listest(10, lo);
	int aux=1;
 	while(aux<=k){
 		cout<<"Ingrese nombre: ";
 		cin>>nombre; 	
		cout<<nombre;
 		cout<<"De la lista de las siguientes carreras:" <<endl;
 		cout<<"1. Electronica ";
 		cout<<"2. Industrial ";
 		cout<<"3. Sistemas ";
 		cout<<"4. Catastral "<<endl;
 		cout<<"Ingrese el número correspondiente de la carrera: ";
 		cin>>j;
		switch(j) 
			{
			    case 1: 
			    	carrera = "Electronica";
			    	break;
			    case 2: 
			    	carrera = "Industrial";
			    	break;
			    case 3: 
			    	carrera = "Sistemas";
			    	break;
			    case 4: 
			    	carrera = "Catastral";
			    	break;
			}	

 		cout<<"Ingrese edad: ";
 		cin>>edad;

		cout<<"De la lista de los siguientes hobbys: "<<endl;
 		cout<<"1. Danza ";
 		cout<<"2. Natacion ";
 		cout<<"3. Basket ";
 		cout<<"4. Beisbol "<<endl;
 		cout<<"Ingrese el número correspondiente del hobby: ";
 		cin>>l;
		switch(l) 
			{
			    case 1: 
			    	hobby = "Danza";
			    	break;
			    case 2: 
			    	hobby = "Natacion";
			    	break;
			    case 3: 
			    	hobby = "Basket";
			    	break;
			    case 4: 
			    	hobby = "Beisbol";
			    	break;
			}	

		listest.insertar_estudiante(nombre, carrera, edad, hobby, aux);
		aux++;
 	}
	
	 cout<<"Los Estudiantes ingresados son:"<<endl;
	 listest.imprimir(lo);
	 cout<<"Estudiantes en orden AZ:"<<endl;
	 listest.imprimirNombreAZ(lo);
	 cout<<"Estudiantes en orden de Edad:"<<endl;
	 listest.imprimirEdad(lo);
	
	 cout<<"Estudiantes de electronica"<<endl;
	 listest.imprimirCarrera("Electronica",lo);
	 cout<<"Estudiantes de Sistemas"<<endl;
	 listest.imprimirCarrera("Sistemas",lo);
	 cout<<"Estudiantes de Industrial"<<endl;
	 listest.imprimirCarrera("Industrial",lo);
	 cout<<"Estudiantes de Catastral"<<endl;
	 listest.imprimirCarrera("Catastral",lo);
	
	 cout<<"Estudiantes Danza"<<endl;
	 listest.imprimirhobby("Danza",lo);
	 cout<<"Estudiantes Natacion"<<endl;
	 listest.imprimirhobby("Natacion",lo);
	 cout<<"Estudiantes Basket"<<endl;
	 listest.imprimirhobby("Basket",lo);
	 cout<<"Estudiantes Beisbol"<<endl;
	 listest.imprimirhobby("Beisbol",lo);
	
    return 0;

}
