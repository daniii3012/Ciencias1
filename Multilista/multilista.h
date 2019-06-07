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

class multi{
	estudiante est[11];	
 	cabecera cab[10];
 	
	public:
		multi(){
			int i;
			cab[0].dato = "Nombre";
 			cab[1].dato = "Electronica";
 			cab[2].dato = "Industrial";
 			cab[3].dato = "Sistemas";
 			cab[4].dato = "Catastral";
 			cab[5].dato = "Edad";
 			cab[6].dato = "Danza";
 			cab[7].dato = "Natacion";
 			cab[8].dato = "Basket";
 			cab[9].dato = "Beisbol";
			
 			for(i=0;i<=10;i++){
 				cab[i].pos = 0;
 			}
		}
		int buscar_por_edad(cabecera cab, int edad);
		int buscar_por_nombre(cabecera cab, string nombre);
		int encontrar_carrera_ant(cabecera cab, int i);
		int encontrar_hobby_ant(cabecera cab, int i);
		void insertar_estudiante(string nombre, string carrera, int edad, string hobby, int i);
		void imprimir();
		void imprimirNombreAZ();
		void imprimirNombreZA();
		void imprimirEdad();
		void imprimirEdadDes();
		void imprimirCarrera(string car);
		void imprimirhobby(string hob);
		void imprimirEstuandCar();
		void imprimirEstuandHob();
		void imprimirCarandHob(string car);
};

int multi::buscar_por_edad(cabecera cab, int edad){
	cabecera aux, aux1;
	aux = cab;
	aux1 = cab;	
	if(cab.pos == 0){
		return 0;				
	}else{
		if(est[aux.pos].sig_edad == 0){
			if(edad > est[aux.pos].edad){
				return 0;			
			}else{
				return 1; 			
			}
		}else{
			if(edad > est[aux.pos].edad){
				return 0;			
			}else{	
				while(est[aux.pos].sig_edad != 0){	
					aux.pos = est[aux.pos].sig_edad;
					if(edad > est[aux.pos].edad){
						return aux1.pos;		
					}
					if(est[aux.pos].sig_edad == 0){
						return aux.pos;		
					}
					aux1 = aux;
				}
			}
		}
	}	
}

int multi::buscar_por_nombre(cabecera cab, string nombre){
	cabecera aux, aux1;
	aux = aux1 = cab;	
	if(cab.pos == 0){
		return 0;				
	}else{
		if(est[aux.pos].sig_nombre == 0){
			if(nombre < est[aux.pos].nombre){
				return 0;			
			}else{
				return 1; 			
			}
		}else{
			if(nombre < est[aux.pos].nombre){
					return 0;			
			}else{	
				while(est[aux.pos].sig_nombre != 0){	
					aux.pos = est[aux.pos].sig_nombre;
					if(nombre < est[aux.pos].nombre){
						return aux1.pos;		
					}
					if(est[aux.pos].sig_nombre == 0){
						return aux.pos;			
					}
					aux1 = aux;
				}
			}
		}
	}	
}

int multi::encontrar_carrera_ant(cabecera cab, int i){
	int aux = cab.pos;
	if (cab.pos == 0){		
		return 0;				
	}else{
		if(est[cab.pos].sig_carrera == 0){		
			return 1;
		}else{	
			while(est[aux].sig_carrera != 0){
				aux = est[aux].sig_carrera;
				if(est[aux].sig_carrera == 0){
					return aux;
				}				
			}		
		}
	}	
}

int multi::encontrar_hobby_ant(cabecera cab, int i){
	int aux = cab.pos;
	if (cab.pos == 0){		
		return 0;				
	}else{
		if(est[cab.pos].sig_hobby == 0){		
			return 1;
		}else{	
			while(est[aux].sig_hobby != 0){
				aux = est[aux].sig_hobby;
				if(est[aux].sig_hobby == 0){
					return aux;
				}				
			}		
		}
	}
}

void multi::insertar_estudiante(string nombre, string carrera, int edad, string hobby, int i){
	estudiante nuevo;
	int nombre_anterior, edad_anterior;	
	nuevo.nombre = nombre;
	nuevo.carrera = carrera;
	nuevo.edad = edad;
	nuevo.hobby = hobby;
	
	nombre_anterior = buscar_por_nombre(cab[0], nombre);	
	if(nombre_anterior == 0){
		if(est[1].nombre == ""){		
			cab[0].pos = 1;			
		}else{					
			nuevo.sig_nombre = cab[0].pos;			
			cab[0].pos = i;
		}		
	}else{				
		nuevo.sig_nombre = est[nombre_anterior].sig_nombre;			
		est[nombre_anterior].sig_nombre = i;		
	}
	
	edad_anterior = buscar_por_edad(cab[5], edad);
	if(edad_anterior == 0){
		if(est[1].edad == 0){					
			cab[5].pos = 1;			
		}else{							
			nuevo.sig_edad = cab[5].pos;			
			cab[5].pos = i;
		}		
	}else{					
		nuevo.sig_edad = est[edad_anterior].sig_edad;			
		est[edad_anterior].sig_edad = i;		
	}	
	
	int pos_carrera = -1;
	if(carrera == "Electronica"){		
		pos_carrera = encontrar_carrera_ant(cab[1], i);
		if(pos_carrera == 0){			
			cab[1].pos = i;			
		}else if(pos_carrera == 1){
			est[cab[1].pos].sig_carrera = i;
		}else{			
			est[pos_carrera].sig_carrera = i;
		}
	}else if(carrera == "Industrial"){
		pos_carrera = encontrar_carrera_ant(cab[2], i);
		if(pos_carrera == 0){
			cab[2].pos = i;			
		}else if(pos_carrera == 1){
			est[cab[2].pos].sig_carrera = i;
		}else{
			est[pos_carrera].sig_carrera = i;
		}	
	}else if(carrera == "Sistemas"){
		pos_carrera = encontrar_carrera_ant(cab[3], i);
		if(pos_carrera == 0){
			cab[3].pos = i;			
		}else if(pos_carrera == 1){
			est[cab[3].pos].sig_carrera = i;
		}else{		
			est[pos_carrera].sig_carrera = i;
		}
	}else if(carrera == "Catastral"){
		pos_carrera = encontrar_carrera_ant(cab[4], i);
		if(pos_carrera == 0){
			cab[4].pos = i;			
		}else if(pos_carrera == 1){
			est[cab[4].pos].sig_carrera = i;
		}else{		
			est[pos_carrera].sig_carrera = i;
		}
	}
	
	int pos_hobby = -1;
	if(hobby == "Danza"){		
		pos_hobby = encontrar_hobby_ant(cab[6], i);
		if(pos_hobby == 0){			
			cab[6].pos = i;			
		}else if(pos_hobby == 1){
			est[cab[6].pos].sig_hobby = i;
		}else{			
			est[pos_hobby].sig_hobby = i;
		}
	}else if(hobby == "Natacion"){
		pos_hobby = encontrar_hobby_ant(cab[7], i);
		if(pos_hobby == 0){
			cab[7].pos = i;			
		}else if(pos_hobby == 1){
			est[cab[7].pos].sig_hobby = i;
		}else{
			est[pos_hobby].sig_hobby = i;
		}	
	}else if(hobby == "Basket"){
		pos_hobby = encontrar_hobby_ant(cab[8], i);
		if(pos_hobby == 0){
			cab[8].pos = i;			
		}else if(pos_hobby == 1){
			est[cab[8].pos].sig_hobby = i;
		}else{		
			est[pos_hobby].sig_hobby = i;
		}
	}else if(hobby == "Beisbol"){
		pos_hobby = encontrar_hobby_ant(cab[9], i);
		if(pos_hobby == 0){
			cab[9].pos = i;			
		}else if(pos_hobby == 1){
			est[cab[9].pos].sig_hobby = i;
		}else{		
			est[pos_hobby].sig_hobby = i;
		}
	}
	est[i] = nuevo;	
}

void multi::imprimirNombreAZ(){
	int a = cab[0].pos;
	for(int i=1;i<11;i++){
		cout<<est[a].nombre<<endl;
		a = est[a].sig_nombre;
	}
	cout<<endl;	
}

void multi::imprimirNombreZA(){
	string nom[11];
	int temp=10;
	int a = cab[0].pos;
	for(int i=1;i<11;i++){
		//cout<<est[a].nombre<<endl;
		nom[temp]=est[a].nombre;
		a = est[a].sig_nombre;
		temp--;
	}
	for(int i=1;i<11;i++){
		cout<<nom[i]<<endl;
	}
	cout<<endl;	
}

void multi::imprimirEdad(){
	int b = cab[5].pos;
	for(int i=1;i<11;i++){
		cout<<est[b].edad<<endl;
		b = est[b].sig_edad;
	}	
	cout<<endl;
}

void multi::imprimirEdadDes(){
	int ed[11];
	int temp=10;
	int b = cab[5].pos;
	for(int i=1;i<11;i++){
		ed[temp]= est[b].edad;
		b = est[b].sig_edad;
		temp--;
	}
	for(int i=1;i<11;i++){
		cout<<ed[i]<<endl;
	}	
	cout<<endl;
}

void multi::imprimir(){
	for(int j=1; j<11; j++){
		cout<<j<<" "<<est[j].nombre<<" "<<est[j].carrera<<" "<<est[j].edad<<" "<<est[j].hobby<<endl;
	}
	
	cout<<endl<<endl<<"Lista de cabeceras:"<<endl<<endl;

	for (int k=0; k<=8; k++){
		cout<<cab[k].dato<<" "<<cab[k].pos<<endl;
	}
	cout<<endl;
}

void multi::imprimirCarrera(string car){
	int b=0;
	if(car=="Electronica"){
		b = cab[1].pos;
	}else if(car=="Industrial"){
		b = cab[2].pos;
	}else if(car=="Sistemas"){
		b = cab[3].pos;
	}else if(car=="Catastral"){
		b = cab[4].pos;
	}
	for(int i=1;i<11;i++){
		cout<<est[b].nombre<<endl;
		b = est[b].sig_carrera;
	}	
	cout<<endl;
}

void multi::imprimirhobby(string car){
	int b;
	if(car=="Danza"){
		b=cab[6].pos;
	}else if(car=="Natacion"){
		b=cab[7].pos;
	}else if(car=="Basket"){
		b=cab[8].pos;
	}else if(car=="Beisbol"){
		b=cab[9].pos;
	}
	for(int i=1;i<11;i++){
		cout<<est[b].nombre<<endl;
		b = est[b].sig_hobby;
	}	
	cout<<endl;
}

void multi::imprimirEstuandCar(){
	int a = cab[0].pos;
	cout<<"Nombre    "<<"Carrera    "<<endl;
	for(int i=1;i<11;i++){
		cout<<est[a].nombre<<"    "<<est[a].carrera<<endl;
		a = est[a].sig_nombre;
	}
	cout<<endl;
}

void multi::imprimirEstuandHob(){
	int a = cab[0].pos;
	cout<<"Nombre    "<<"Hobby    "<<endl;
	for(int i=1;i<11;i++){
		cout<<est[a].nombre<<"    "<<est[a].hobby<<endl;
		a = est[a].sig_nombre;
	}
	cout<<endl;
}

void multi::imprimirCarandHob(string car){
	int b=0;
	int nat=0,dan=0,bas=0,bei=0;
	if(car=="Electronica"){
		b = cab[1].pos;
	}else if(car=="Industrial"){
		b = cab[2].pos;
	}else if(car=="Sistemas"){
		b = cab[3].pos;
	}else if(car=="Catastral"){
		b = cab[4].pos;
	}
	for(int i=1;i<11;i++){
		if(est[b].hobby=="Natacion"&&nat==0){
			cout<<est[b].hobby<<endl;
			b = est[b].sig_nombre;
			nat=1;
		}else if(est[b].hobby=="Danza"&&dan==0){
			cout<<est[b].hobby<<endl;
			b = est[b].sig_nombre;
			dan=1;
		}else if(est[b].hobby=="Basket"&&bas==0){
			cout<<est[b].hobby<<endl;
			b = est[b].sig_nombre;
			bas=1;
		}else if(est[b].hobby=="Beisbol"&&bei==0){
			cout<<est[b].hobby<<endl;
			b = est[b].sig_nombre;
			bei=1;
		}else{
			b = est[b].sig_nombre;
		}
	}
	cout<<endl;
}

#endif
