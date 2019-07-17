#include <cstdlib>
#include <iostream>
#include <ctype.h>
#include <iomanip>
#include "pila.h"
#include "cola.h"

using namespace std;

int main(int argc, char *argv[]){
	cola Cola; 
	pila Pila[2]; 
 	int i,j, tam, grupo=0, orden[2];
 	char x; 
  
 	do{
   		cout<<"Escriba un multiplo de 2: ";
   		cin>> tam;}
 	while (tam%2!=0);
 	
 	i=1;
 	x=32; // o 32
 	cout<<x;
 	
 	while(i<=tam && i<255){ 
	 	if((x==0)||(x==13)||(x==32)||(x>6&&x<11))
        	x++;
     	else {
		 	Cola.InsCola(x);
        i++;
		x++;
       	}
  	}
 	cout<<"Elija uno de los símbolos que aparecen a continuación: \n";

	for(int k=1; k<=tam/2; k++){
		cout<<"  Gr1  "<<"Gr2  "<<endl;
  		while (!Cola.ColaVacia()){
		  	for (i=0; i<2; i++){
			  	x=Cola.AtenderCola();
       			cout<<setw(4)<< x;
       			Pila[i].Push(x);
       		}
    	cout<<"\n"; 
    	}
 
   		cout<< "Elija el grupo en el que quedò el simbolo elegido (1 o 2): ";
  		cin>> grupo;
  		
  		switch(grupo){
        	case 1 : {orden[0]=0; orden[1]=1; j=(tam/2)-1; break; }//orden[2]=2;break;}
         	case 2 : {orden[0]=1; orden[1]=0; j=(tam/2); break; } //orden[2]=2;break;}       
         	//case 3 : {orden[0]=0; orden[1]=2; //orden[2]=1;break;}       
        }
        
  		for (i=0; i<2; i++){
		  	while (!Pila[orden[i]].PilaVacia()){
			  	Cola.InsCola(Pila[orden[i]].Pop());
			}
    	}
  	}
	
	
	for (i=1; i<=j; i++){
		x=Cola.AtenderCola();
	}
	cout<<"La figura elegida es: "<< x<<endl; 
    system("PAUSE");
    return EXIT_SUCCESS;
}
