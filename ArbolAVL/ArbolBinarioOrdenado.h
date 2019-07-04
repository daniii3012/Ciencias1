/*
	Daniel Alejandro Montiel - 20171020049
	Angie Gabriela Antolinez - 20151020061
*/

#ifndef ARBOLBINARIOORDENADO_H_ 
#define ARBOLBINARIOORDENADO_H_ 
#include "Nodo.h"

template<class T>
class BinarySearchTree {
protected:
	Node<T>* root;
	int (*ptr)(T, T);
	Node<T>* findMin(Node<T>*);
	Node<T>* findMax(Node<T>*);
	Node<T>* insert(T, Node<T>*);
	Node<T>* remove(T, Node<T>*);
private:
	Node<T>* find(T, Node<T>*);
	void inOrder(Node<T>*);
	void preOrder(Node<T>*);
	void postOrder(Node<T>*);
	void perLevel(Node<T>*);
	void printArms(Node<T>*);
public:
	BinarySearchTree(int (*ptr)(T, T));
	~BinarySearchTree();
	Node<T>* getRoot();
	void add(T);
	void remove(T);
	Node<T>* search(T);
	void showInOrder();
	void showPreOrder();
	void showPostOrder();
	void showPerLevel();
};

#include "ArbolBinarioOrdenado.cpp"

#endif /* ARBOLBINARIOORDENADO_H_ */
