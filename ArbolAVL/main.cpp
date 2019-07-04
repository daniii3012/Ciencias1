/*
	Daniel Alejandro Montiel - 20171020049
	Angie Gabriela Antolinez - 20151020061
*/

#include <iostream>	
#include <stdlib.h>	
#include "Nodo.cpp"	
#include "ArbolAVL.h"	
#include "ArborBinarioOrdenado.h"	

 using namespace std;	
int comparar(int a, int b);	

 template <class T>	
void verArbol( Node<T>* Node, int n){	
     if(Node==NULL)	
          return;	
     verArbol(Node->getRight(), n+1);	

      for(int i=0; i<n; i++)	
         cout<<"\t\t";	

      cout<< Node->getData() <<endl;	

      verArbol(Node->getLeft(), n+1);	
}	

 int main(int argc, char **argv) {	
	int (*fptr)(int, int);	
	fptr = comparar;	
	AVLTree<int>* avl = new AVLTree<int>(fptr);	
	
	avl->add(1);	
	avl->add(2);	
	avl->add(3);	
	avl->add(4);	
	avl->add(5);	
	avl->add(6);	
	avl->add(7);	

 	cout << "En orden" << endl;	
	avl->showInOrder();	
	cout << endl << "Preorden" << endl;	
	avl->showPreOrder();	
	cout << endl << "Posorden" << endl;	
	avl->showPostOrder();	
	cout << endl << "Por niveles" << endl;	
	avl->showPerLevel();	

// 	cout << endl<<"AVL TREE - Preorden" << endl;	
//	cout << endl<<" Completa       : ";	
//	avl->showPreOrder();	
//	cout << endl<<" Borrar Augusto : ";	
//	avl->remove("Augusto");	
//	avl->showPreOrder();	
//	cout << endl<<" Borrar Felipe  : ";	
//	avl->remove("Felipe");	
//	avl->showPreOrder();	
//	cout << endl<<" Borrar Juan    : ";	
//	avl->remove("Juan");	
//	avl->showPreOrder();	

 	system("pause");	
	return 0;	
}	

 int comparar(int a, int b) {	
 	int x;
 	if(a==b)
 		x=0;
 	if(a<b)
 		x=-1;
 	else 
 		x=1;
	return x;
}
