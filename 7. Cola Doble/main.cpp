/*
	Daniel Alejandro Montiel - 20171020049
	Angie Gabriela Antolinez - 20151020061
*/
#include <iostream>
#include "coladoble.h"
using namespace std;

int main(){
	cola_doble<int> p;
	p.enqueue(3, 'I');
	p.enqueue(8, 'D');
	p.enqueue(10, 'I');
	p.dequeue('D');
	p.enqueue(12, 'D');
	p.dequeue('I');
	p.imprimir('I');
	cout << endl;
	p.imprimir('D');
	return 0;
}
