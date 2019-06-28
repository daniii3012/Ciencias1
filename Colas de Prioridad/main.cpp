#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "cola_prioridad.h"
using namespace std;

int main(){
	
	PriorityQueue pq;
	
	while (1){
        cout << "1) Insertar Elemento" << endl;
        cout << "2) Imprimir" << endl;
        cout << "3) Atender" << endl;
        cout << "4) Salir" << endl;
        
        int opc, num;
        cout << "Ingrese una opcion: ";
        cin >> opc;
        
        switch(opc){
        case 1:        	
            cout << "Numero a insertar: ";
            cin >> num;
            pq.push(num);
            system("cls");
            break;
            
        case 2:
        	system("cls");
            cout << "Cola de Prioridad:  ";
            pq.print();
            break;
            
        case 3:
        	system("cls");
            cout << "Atender: ";
            cout << pq.top() << " " << endl;;
			pq.pop();
            break;
            
        case 4:
            exit(1);
        default:
            cout<<"Ingrese una opcion correcta"<<endl;
        }
    }
    
	return 0;
}
