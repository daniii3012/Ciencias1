#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "cola_prioridad.h"
using namespace std;

int main()
{
	PriorityQueue pq;
	
	pq.push(60);
	pq.push(80);
	pq.push(20);
	pq.push(90);
	pq.push(50);
	pq.push(40);
	pq.push(30);
	pq.push(70);
	pq.push(55);
	pq.push(45);
	
	pq.print();
	cout << endl;
	
	cout << pq.top() << " " << endl;;
	pq.pop();
	
	pq.print();
	
	/*
	// Note - Priority is decided by element's value
	
	pq.push(3);
	pq.push(2);
	pq.push(15);
	
	cout << "Size is " << pq.size() << endl;	
	
	cout << pq.top() << " ";
	pq.pop();

	cout << pq.top() << " ";
	pq.pop();

	pq.push(5);
	pq.push(4);
	pq.push(45);

	cout << endl << "Size is " << pq.size() << endl;
	
	cout << pq.top() << " ";
	pq.pop();

	cout << pq.top() << " ";
	pq.pop();

	cout << pq.top() << " ";
	pq.pop();

	cout << pq.top() << " ";
	pq.pop();

	cout << endl << std::boolalpha << pq.empty();
	
	pq.top();	// top operation on an empty heap
	pq.pop();	// pop operation on an empty heap
	*/
	return 0;
}
